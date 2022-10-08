#ifndef GUARD_PSO_H
#define GUARD_PSO_H

#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>

struct particle {                          //单个粒子
	std::vector<double> pBest;
	std::vector<double> v;
	std::vector<double> x;
};

template<typename func>
class PSO
{
public:
	// 构造函数，在类构造时初始化：目标函数、变量个数、定义域、最大速度
	PSO(func f, int vnum, double bound):NVARS(vnum),absbound(bound),vmax(0.15*bound),fp(f)
	{
		gBest.resize(NVARS);
		particles.resize(POPSIZE);
	};

	void initialize();                      	//初始化函数
	double randval(double, double);             //求范围（lower，upper）之间的随机数
	void evaluate();                        	//评估粒子适应值
	void update();                              //利用更新公式更新每个粒子的速度和位置以及历史最优位置
	void fit();                             	//更新群体历史最优位置
	void run(bool out = true);					//运行模型

private:
	// 模型参数
	const int POPSIZE = 20;                     //粒子个数
	const int MAXINTERATION = 100;             	//最大迭代次数
	const double WMAX = 0.8;                    //惯量权重最大值
	const double WMIN = 0.4;                    //惯量权重最小值
	const double c1 = 2.0;                      //加速因子1
	const double c2 = 2.0;                      //加速因子2

	// 目标函数参数
	const double absbound;                      //上下界绝对值（函数定义域）
	const double vmax;                          //最大速度
	const func fp;								//目标函数指针
	const int NVARS;                        	//函数参数个数

	// 私有成员变量
	double w;                                   //惯量权重
	std::vector<double> gBest;                  //全局最优解
	std::vector<particle> particles;            //粒子群
};

template<typename func>
double PSO<func>::randval(double low, double high) {
    // 生成随机数
	return (low + (high - low)*rand()*1.0 / RAND_MAX);
}


template<typename func>
void PSO<func>::initialize() {
    // 初始化每个粒子的速度和位置
    // 暂时将该位置设置为历史最优位置
    // 从中选出一个最优位置，作为全局的最优位置
	int i, j;
    // 随机初始化每个粒子的速度与位置
    // 并将其设置为当前粒子的历史最佳位置
	for (i = 0; i < POPSIZE; i++) {
		for (j = 0; j < NVARS; j++) {
			particles[i].v.push_back(randval(-absbound, absbound));
			particles[i].x.push_back(randval(-absbound, absbound));
			particles[i].pBest.push_back(particles[i].x[j]);
		}
	}
    // 用pval维护所有粒子评估的最小值（即最佳位置的取值）
	double pval = fp(particles[0].pBest);
	int num;
	for (i = 1; i < POPSIZE; i++) {
        double nval = fp(particles[i].pBest);
		if (pval > nval) {
			pval = nval;
			num = i;
		}
		else continue;
	}
    // gBest维护全局的最佳位置
	for (j = 0; j < NVARS; j++) {
		gBest[j] = particles[num].pBest[j];
	}
}


template<typename func>
void PSO<func>::evaluate() {
	
	int i, j;
	std::vector<double> pval(POPSIZE),nval(POPSIZE);
 
	for (i = 0; i < POPSIZE; i++) {
        // 求当前粒子的历史最佳位置的评估值和现在位置的评估值
        // 如果现在的评估值更佳，则更新历史最佳位置，即pBest
		pval[i] = fp(particles[i].pBest);
		nval[i] = fp(particles[i].x);
 
		if (pval[i] > nval[i]) {
			for (j = 0; j < NVARS; j++) {
				particles[i].pBest[j] = particles[i].x[j];
			}
		}
	}
}


template<typename func>
void PSO<func>::update() {
	// 更新w
    // 并更新的速度和位置
	int i, j;
	double v, x;
 
    // 维护w
    w = randval(0.4, 0.6);
    
    // 更新粒子速度和位置
	for (i = 0; i < NVARS; i++) {
		for (j = 0; j < POPSIZE; j++) {

            // 更新速度的核心公式
			v = w*particles[j].v[i] + c1*randval(0, 1)*(particles[j].pBest[i] - particles[j].x[i])
				 + c2*randval(0, 1)*(gBest[i] - particles[j].x[i]);
			// 控制速度不越界
            if (v > vmax) particles[j].v[i] = vmax;
			else if (v < (-vmax)) particles[j].v[i] = (-vmax);
			else particles[j].v[i] = v;

            // 更新位置的核心公式
			x = particles[j].x[i] + particles[j].v[i];
            // 控制位置在定义域内
			if (x > absbound)particles[j].x[i] = absbound;
			else if (x < -absbound)particles[j].x[i] = -absbound;
			else particles[j].x[i] = x;
		}
	}
}


template<typename func>
void PSO<func>::fit() {
	// 更新群体最优位置
	int i, j;
	double gval = fp(gBest);
 
	for (i = 0; i < POPSIZE; i++) {
		double pval = fp(particles[i].pBest);
 
		if (gval > pval) {
			for (j = 0; j < NVARS; j++) {
				gBest[j] = particles[i].pBest[j];
			}
		}
	}
}


template<typename func>
void PSO<func>::run(bool out){

	std::ofstream fout("data.csv");

	initialize();							// 随机初始化每个粒子的位置和速度
    for (int i = 0; i < MAXINTERATION; i++) {
        update();							// 更新每个粒子的位置和速度
        evaluate();							// 对每个粒子，维护最佳位置
        fit();								// 维护全局的最佳位置
        double evalue = fp(gBest);
        if(out) fout << evalue<<'\n';
    }
}


#endif
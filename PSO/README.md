# 粒子群算法：

- 1 PSO 粒子群算法

``` C++
PSO(typename func f, int vnum, double bound)        //构造函数
void initialize();                      	        //初始化函数
double randval(double, double);                     //求范围（lower，upper）之间的随机数
void evaluate();                        	        //评估粒子适应值
void update();                                      //利用更新公式更新每个粒子的速度和位置以及历史最优位置
void fit();                             	        //更新群体历史最优位置
void run(bool out = true);					        //运行模型

```
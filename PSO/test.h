#pragma once

#include<iostream>
#include"PSO.h"
#include<cmath>
#include<random>
#include<ctime>


// 定义了一个目标函数，我们求它的最小值， x[i]的定义域为[-10,10]
double f (std::vector<double> x){
    double a=0,b=1.0;
    for(int i=0;i<x.size();i++) a += x[i]*x[i]/4000;
    for(int i=0;i<x.size();i++) b *= cos(x[i]/sqrt(i+1));
    return a-b+1;
}

void test_PSO(){
    srand(time(NULL));

    PSO model(f,5,10);
    model.run(false);

    system("pause");
}
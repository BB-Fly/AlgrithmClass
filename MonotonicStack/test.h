#pragma once

#include<iostream>
#include<vector>
#include"MonotonicStack.h"

const int N = 100;

std::string randstr() {
	int len = rand() % N;
	char tmp = ('a' + rand() % 26);
	std::string ans;
	ans += tmp;
	for (int i = 0; i < len; i++) {
		tmp = ('a' + rand() % 26);
		ans += tmp;
	}
	return ans;
}

template<class T>
bool cmp(T& x, T& y) { return x < y; }

bool test_MonotonicStack() {
	std::vector<std::string> List(N);
	srand(time(NULL));
	for (int i = 0; i < N; i++) { List[i] = randstr(); std::cout << i << ':' << List[i] << '\n';}
	MonotonicStack<std::string> x(List, cmp, true);
	for (int i = 0; i < N; i++) std::cout << i << ':' << x.Next(i) << '\n';
	return true;
}
#include"BOM_UnionFind.h"
#include"UnionFind.h"
#include<ctime>
#include<vector>
#include<iostream>

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

bool test_unionfind() {
	srand(time(NULL));
	std::vector<std::vector<int>> G(N, std::vector<int>(2));
	UnionFind x(N);
	for (int i = 0; i < N; i++) {
		G[i] = { rand() % N, rand() % N };
	}
	for (int i = 0; i < N; i++) {
		x.unite(G[i][0], G[i][1]);
		std::cout << G[i][0] << '-' << G[i][1] << '\t';
	}
	std::cout << x.Count() << std::endl;
	return true;
}

bool test_BOM_unionfind() {
	std::vector<std::string> List(N);
	srand(time(NULL));
	for (int i = 0; i < N; i++) List[i] = randstr();
	std::vector<std::vector<int>> G(N, std::vector<int>(2));
	BOM_UnionFind<std::string> x;
	for (int i = 0; i < N; i++) {
		G[i] = { rand() % N, rand() % N };
	}
	for (int i = 0; i < N; i++) {
		x.unite(List[G[i][0]],List[G[i][1]]);
		std::cout << G[i][0] << '-' << G[i][1] << '\t';
	}
	std::cout << x.Count() << std::endl;
	return true;
}

#include"test.h"
#include<iostream>

using namespace std;

const int N = 100;

string randstr() {
	int len = rand() % N;
	char tmp = ('a' + rand() % 26);
	string ans;
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
	vector<vector<int>> G(N, vector<int>(2));
	UnionFind x(N);
	for (int i = 0; i < N; i++) {
		G[i] = { rand() % N, rand() % N };
	}
	for (int i = 0; i < N; i++) {
		x.unite(G[i][0], G[i][1]);
		cout << G[i][0] << '-' << G[i][1] << '\t';
	}
	cout << x.Count() << endl;
	return true;
}

bool test_BOM_unionfind() {
	vector<string> List(N);
	srand(time(NULL));
	for (int i = 0; i < N; i++) List[i] = randstr();
	vector<vector<int>> G(N, vector<int>(2));
	BOM_UnionFind<string> x;
	for (int i = 0; i < N; i++) {
		G[i] = { rand() % N, rand() % N };
	}
	for (int i = 0; i < N; i++) {
		x.unite(List[G[i][0]],List[G[i][1]]);
		cout << G[i][0] << '-' << G[i][1] << '\t';
	}
	cout << x.Count() << endl;
	return true;
}

bool test_MonotonicStack() {
	vector<string> List(N);
	srand(time(NULL));
	for (int i = 0; i < N; i++) { List[i] = randstr(); cout << i << ':' << List[i] << '\n';}
	MonotonicStack<string> x(List, cmp, true);
	for (int i = 0; i < N; i++) cout << i << ':' << x.Next(i) << '\n';
	return true;
}
#include"test_UnionFind.h"

string randstr() {
	const int N = 100;
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

bool test_unionfind() {
	const int N = 100;
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
	const int N = 100;
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
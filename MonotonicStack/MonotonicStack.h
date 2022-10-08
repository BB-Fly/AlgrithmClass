#pragma once

#include<stack>
#include<vector>

template<class T>
class MonotonicStack {
private:
	int* nxt;
public:
	MonotonicStack(std::vector<T>& vec, bool (*func)(T& x,T& y), bool isleft = false) {
		int len = vec.size();
		nxt = new int[len];
		std::stack<int> s;
		if (!isleft) {
			for (int i = 0; i < len; i++) {
				nxt[i] = len;
				while (!s.empty() && func(vec[s.top()], vec[i])) {
					nxt[s.top()] = i;
					s.pop();
				}
				s.push(i);
			}
		}
		else {
			for (int i = len - 1; i >= 0; i--) {
				nxt[i] = -1;
				while (!s.empty() && func(vec[s.top()], vec[i])) {
					nxt[s.top()] = i;
					s.pop();
				}
				s.push(i);
			}
		}
	}
	~MonotonicStack() { delete nxt; }
	int Next(int x) { return nxt[x]; }
};
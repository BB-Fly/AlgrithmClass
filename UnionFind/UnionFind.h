#pragma once

#include<cstring>

class UnionFind{
private:
    int *rank, *parents;
    size_t cnt;
    int _find(int idx) {
        if (idx != parents[idx]) parents[idx] = _find(parents[idx]);
        return parents[idx];
    }
public:
    UnionFind(int n){
        rank = new int[n];
        parents = new int[n];
        cnt=n;
        for (int i = 0; i < n; i++) { parents[i] = i; rank[i] = 0; }
    }

    ~UnionFind(){
        delete rank;
        delete parents;
    }

    void unite(int x,int y){
        int _x=_find(x),_y=_find(y);
        if(_x!=_y){
            if(rank[_x]>rank[_y]) parents[_y]=_x;
            else if(rank[_x]<rank[_y]) parents[_x]=_y;
            else{parents[_x]=_y;rank[_y]++;}
            cnt--;
        }
    }

    bool Same(int x, int y) {
        return _find(x) == _find(y);
    }

    size_t Count(){return cnt;}
};
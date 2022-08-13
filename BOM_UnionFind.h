#pragma once

#include<cstring>
#include<unordered_map>
#include<utility>

template<class T>
class BOM_UnionFind{
private:
    size_t cnt;
    std::unordered_map<T,std::pair<T,int>> prt_rank;
    T find(T idx) {
        if (prt_rank.count(idx) == 0) { prt_rank[idx] = { idx,0 }; cnt++; }
        else if (idx != prt_rank[idx].first) prt_rank[idx].first = find(prt_rank[idx].first);
        return prt_rank[idx].first;
    }
public:
    void unite(T x,T y){
        T _x=find(x), _y=find(y);
        if(_x!=_y){
            if(prt_rank[_x].second>prt_rank[_y].second) prt_rank[_y].first=_x;
            else if(prt_rank[_x].second<prt_rank[_y].second) prt_rank[_x].first=_y;
            else{prt_rank[_x].first=_y;prt_rank[_y].second++;}
            cnt--;
        }
    }

    size_t Count(){return cnt;}
};
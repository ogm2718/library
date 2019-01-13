#include <iostream>
#include <algorithm>

class UnionFind{
  int v[MAX];
  int deep[MAX];
  public:
  UnionFind(){
    for(int i=1;i<MAX;i++){
      v[i]=i;
      deep[i] = 0;
    }
  }
   
  int root(int x){
    if(v[x]==x)return x;
    else return v[x] = root(v[x]);
  }

  bool same(int x, int y){
    return (root(x) == root(y));
  }

  void unite(int x,int y){
    x = root(x);
    y = root(y);
    if(deep[x] > deep[y]){
            v[y] = x;
    }else{
      if(deep[x] == deep[y])deep[y]++;
      v[x] = y;
    }
    return;
  }
}

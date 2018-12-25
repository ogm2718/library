#define inf (int)1e9
int n;
long long v[n][n];
int s;
for(int k=0;k<n;++k){
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      if(v[i][k]!=inf && v[k][j]!=inf){
        v[i][j] = min(v[i][j],v[i][k]+v[k][j]);
      }
    }
  }
}

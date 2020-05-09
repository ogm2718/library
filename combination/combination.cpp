#include <iostream>
#include <algorithm>
using namespace std;

long long MOD = 1e9 +7;
long long factrial[5000000]; //再帰が深くなるとスタックオーバーフローになるので最初に使うものは初期化しておく

long long init(){
  factrial[0]=1;
  for(i=1;i<5000000;i++)factrial[i] = (factrial[i-1] * i) % MOD;
}

long long Repeat(long long a,long long cnt){
  if(cnt==0)return 1LL;
  if(cnt%2==1){
    long long x = Repeat(a,cnt/2);
    return (((a*x)%MOD)*x)%MOD;
  }
  else {
    long long x = Repeat(a,cnt/2);
    return (x*x)%MOD;
  }
}

long long fact(long long a){
  if(a == 0)return 1LL;
  else if(factrial[a]!=0)return factrial[a];
  else return factrial[a] = (a*fact(a-1))%MOD;
}

long long comb(long long a, long long b){
  long long fa,fb,fab;
  fa = fact(a);
  fb = fact(b);
  fab = fact(a-b);
  fb = Repeat(fb,MOD-2);
  fab = Repeat(fab,MOD-2);
  return (((fa*fb)%MOD)*fab)%MOD;
}

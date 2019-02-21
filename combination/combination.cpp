#include <iostream>
#include <algorithm>
using namespace std;

long long MOD = 1e9 +7;

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
  else return (a*fact(a-1))%MOD;
}

long long conb(long long a, long long b){
  long long fa,fb,fab;
  fa = fact(a);
  fb = fact(b);
  fab = fact(a-b);
  fb = Repeat(fb,MOD-2);
  fab = Repeat(fab,MOD-2);
  return (((fa*fb)%MOD)*fab)%MOD;
}

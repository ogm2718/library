long long Repeat(long long a,long long cnt){
  if(cnt==0)return 1;
  if(cnt%2==1){
    long long x = Repeat(a,cnt/2);
    return a*x*x;
  }
  else {
    long long x = Repeat(a,cnt/2);
    return x*x;
  }
}

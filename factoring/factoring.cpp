vector<long long> facttoring(long long p){
  vector<long long> fact(p,0);
  for(i=2;i*i<=p;i++){
    while(p%i==0){
      fact[i]++;
      p/=i;
    }
  }
  if(p>1)fact[p]++;
  return fact;
}

//fact[i] == (pに含まれる素因数iの個数)

<<<<<<< HEAD
vector<long long> factoring(long long p){
=======
vector<long long> facttoring(long long p){
>>>>>>> 0a7ba92cae80f664b0fa54f34b87063a39cb2e80
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

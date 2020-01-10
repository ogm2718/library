template<typename T>
T gcd(T x, T y){
  return x ? gcd(y%x,x) : y;
}
template<typename T>
T lcm(T x,T y){
  return x/gcd(x,y)*y;
}

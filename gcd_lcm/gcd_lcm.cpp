#include <iostream>

using namespace std;

int gcd(int x, int y){
  return x ? gcd(y%x,x) : y;
}

int lcm(int x,int y){
  return x*y/gcd(x,y);
}

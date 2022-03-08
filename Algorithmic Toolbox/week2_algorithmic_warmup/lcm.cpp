#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;
  return (long long) a * b;
}

//Recursive implementation of the gcd using lemma
int gcd_euclid(int first, int second) {
  int a;
  int b;
  //In case the inputs are encoded in a non standard way
  if(first >= second){
    a = first;
    b = second;
  }
  else{
    a = second;
    b = first;
  }
  if(b == 0)
  {
    return a;
  }
  int a_prime = a % b;
  return gcd_euclid(b, a_prime);
}

//Special implementation using the gcd_fast
long long lcm_fast(int a, int b) {
  if(a == 0 || b == 0){
    return 0;
  }

  int gcd = gcd_euclid(a, b);
  return (long long) a * b / gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}

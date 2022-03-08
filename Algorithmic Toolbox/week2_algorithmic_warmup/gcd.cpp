#include <iostream>
#include <cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
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

void test_solution(){
  assert(gcd_euclid(100, 50) == 50); //Trivial case
  assert(gcd_euclid(400, 80000) == 400); //Inverted input case
  assert(gcd_euclid(1, 0) == 1);
  assert(gcd_euclid(0, 0) == 0); //Null case
  assert(gcd_euclid(3918848, 1653264) == 61232); //Big number case

  //Stress test
  for (int n = 0; n < 20; ++n){
    int a = rand();
    int b = rand();
    std::cout << a << " ";
    std::cout << b << " ";
    assert(gcd_euclid(a, b) == gcd_naive(a, b));
  }
}

int main(){
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_euclid(a, b) << std::endl;
  //test_solution();
  return 0;
}

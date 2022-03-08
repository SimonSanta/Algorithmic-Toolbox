#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int get_change(int m) {
  //Greedy algorithm implmentation
  int current_m = m;
  int count = 0;
  
  vector<int> coins {10, 5, 1}; //sorted array reduces complexity
  for(int i = 0; i < coins.size(); ++i){
    if(current_m >= coins[i]){
        int a = current_m / coins[i];
        count += a;
        current_m = current_m % coins[i];     
    }
  }
  return count;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

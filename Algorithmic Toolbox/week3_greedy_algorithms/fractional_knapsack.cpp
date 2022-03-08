#include <iostream>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <iomanip>      // set precision

std::vector<int> sort_indexes_ratio(const std::vector<double> &v) {

  std::vector<double> w = v;
  // Initialize original index locations
  std::vector<int> idx(v.size());
  std::iota(idx.begin(), idx.end(), 0);

  // Sort indexes, v based on comparing values in v
  // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings
  // when v contains elements of equal values 
  std::stable_sort(idx.begin(), idx.end(),
       [&v](double i1, double i2) {return v[i1] > v[i2];});
  return idx;
}

double get_optimal_value(int capacity, std::vector<int> weights, std::vector<int> values) {

  double value = 0.0;
  int current_capacity = capacity;

  // Compute initial price/weight ratio vector
  std::vector<double> ratio(weights.size(), 0.0);

  for(int i = 0; i < weights.size(); ++i){
    ratio[i] = ((double)((double)values[i]) / ((double)weights[i]));
  }

  // Sort ratio and return sorted indexes
  std::vector<int> indexes = sort_indexes_ratio(ratio);
  std::vector<double> new_ratio(weights.size(), 0.0);

    for(int i = 0; i < weights.size(); ++i){
    new_ratio[i] = ratio[indexes[i]];
    }
    ratio = new_ratio;

  // Greedy algorithm implementation
  for(int i  = 0; i < weights.size(); ++i){
    if(current_capacity == 0){
      return value;
    }
    if(current_capacity >= weights[indexes[i]])
    {
      value += values[indexes[i]];
      current_capacity -= weights[indexes[i]];
    }
    else{
      value = ((double)value) + ((double)current_capacity) * ((double)ratio[i]);
      current_capacity -= current_capacity;
    }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  std::vector<int> values(n);
  std::vector<int> weights(n);

  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  // Testing
  // Compute initial price/weight ratio vector
  // std::vector<double> ratio(weights.size(), 0.0);

  // for(int i = 0; i < weights.size(); ++i){
  // ratio[i] = values[i] / weights[i];
  // std::cout << ratio[i] << "\n";
  // }

  // std::vector<int> indexes = sort_indexes_ratio(ratio);
  // for(int i = 0; i < ratio.size(); ++i){
  //   std::cout << indexes[i] << std::endl;
  // }

  double optimal_value = get_optimal_value(capacity, weights, values);
  
  std::cout << std::fixed;
  std::cout << std::setprecision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}

#include <iostream>

long long get_fibonacci_huge_quick(long long n, long long m) {
    if (n <= 1)
        return n;
    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }
    return current;
}

long long get_period(long long m){
    long long prev = 0;
    long long current = 1;
    long long i = 2;
    while((prev != 0 || current != 1 || i == 2)){
        long long new_current = (prev + current) % m;
        prev = current;
        current = new_current;
        ++i;
        //std::cout << i << " ";
    }
    long long period = i - 2;
    return period;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    long long period, reminder, final_result;
    if(n % m < n){
        period = get_period(m);
        //std::cout << '\n'<< period << '\n';;
        reminder = n % period;
        final_result = get_fibonacci_huge_quick(reminder, m);
        std::cout << final_result << '\n';
    }
    else{
        final_result = get_fibonacci_huge_quick(n, m);
        std::cout << final_result << '\n';
    }
    return 0;
}

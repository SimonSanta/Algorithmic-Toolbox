#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

long long MaxPairwiseProduct(const vector<int>& numbers){
    long long result = 0;
    int n = numbers.size();
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(((long long)numbers[i])*numbers[j] > result)
            {
                result = ((long long)numbers[i])*numbers[j];
            }
        }
    }
    return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers){

    long long result = 0;
    int n = numbers.size();
    int max_index1 = -1;
    int max_index2 = -1;

    for(int i = 0; i < n; ++i){
        if(max_index1 == -1 || numbers[i] > numbers[max_index1]){
            max_index1 = i;
        }
    }
    for(int j = 0; j < n; ++j){
        if((max_index2 == -1 || (numbers[j] > numbers[max_index2])) && (j != max_index1)){
            max_index2 = j;
        }
    }
    result = ((long long) numbers[max_index1]) * numbers[max_index2];
    return result;
}

int main(){

/*    while(true){
        int n = rand() % 1000 + 2;
        cout << n << "\n";
        vector<int> a;
        for(int i = 0; i < n; ++i){
            a.push_back(rand() % 100000);
            cout << a[i] << " ";
        }
        cout << "\n";

        long long result1 = MaxPairwiseProduct(a);
        long long result2 = MaxPairwiseProductFast(a);
        if(result1 != result2){
            cout << "Wrong answer " << result1 << " " << result2 << "\n";
            break;
        }
        else{
            cout << "OK" << "\n";
        }
    }
*/
    int n {};
    cin >> n;
    vector<int> numbers(n);
    for(int i = 0; i < n; ++i){
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProductFast(numbers);
    cout << result << "\n";
    return 0;

}
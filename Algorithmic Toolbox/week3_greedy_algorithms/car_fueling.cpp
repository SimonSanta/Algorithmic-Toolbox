#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

// Compute distances between each stops from departure to arrival
vector<int> new_stops(const vector<int> &stops, int dist){

    int n = stops.size();
    vector<int> stop_vec(n + 1, 0);

    for(int i = 0; i < n; ++i){
        stop_vec[i + 1] = stops[i]; //compute the distance between each stop
    }

    stop_vec[n + 1] = dist;
    return stop_vec;
}

int compute_min_refills(int dist, int tank, vector<int> &stops) {
    // Implementation using Greedy algorithm with particular
    // Dividing the problem into a subproblem and applying optimization at each stages

    int n = stops.size();
    // Modified vector with distances between stops
    vector<int> stopDist = new_stops(stops, dist);

    int nRefill = 0;
    int currentStop = 0;
    while(currentStop <= n){

        int lastStop = currentStop;
        while(currentStop <= n && ((stopDist[currentStop + 1] - stopDist[lastStop]) <= tank)){
            ++currentStop;
        }

        if(currentStop == lastStop){
            return -1;
        }
        if(currentStop <= n){
            ++nRefill;
        }
    }
    return nRefill;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
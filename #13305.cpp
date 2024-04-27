/*
BaekJoon No
#13305
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    int distance[n-1];
    for(int i=0; i<n-1; ++i)
        cin >> distance[i];

    long long prefixSum[n-1];
    prefixSum[0] = distance[0];
    for(int i=1; i<n-1; ++i)
        prefixSum[i] = prefixSum[i-1] + distance[i];



    vector<pair<int, int> > greedy;
    int price;
    for(int i=0; i<n; ++i){
        cin >> price;
        greedy.push_back(make_pair(price, i));
    }

    sort(greedy.begin(), greedy.end(), [](pair<int, int> a, pair<int, int> b) -> bool{
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });

    

    long long result = 0;
    int endCityIdx = n-1;
    for(auto e : greedy){
        if(e.second >= endCityIdx)  continue;

        long long totalDistance = e.second > 0 ? prefixSum[endCityIdx-1] - prefixSum[e.second-1] : prefixSum[endCityIdx-1];
        result += e.first * totalDistance;
        
        if(e.second == 0)   break;
        endCityIdx = e.second;
    }

    cout << result;

    return 0;
}
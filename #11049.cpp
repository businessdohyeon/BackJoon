/*
BaekJoon No
#11049
*/

#include <iostream>
#include <vector>

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

    vector<pair<int, int> > input(n);
    for(int i=0; i<n; ++i)
        cin >> input[i].first >> input[i].second;

    int dp[n][n];
    for(int idx=0; idx<n; ++idx){
        for(int start=0, end=idx; start<n && end<n; ++start, ++end){
            if(start == end){
                dp[start][end] = 0;
            }else if(end == start+1){
                dp[start][end] = input[start].first * input[start].second * input[end].second;
            }else{
                int min = -1;
                for(int mid=start; mid<=end-1; ++mid){
                    int cal = dp[start][mid]+dp[mid+1][end]+input[start].first*input[mid].second*input[end].second;
                    if(min == -1 || cal < min)
                        min = cal;
                }
                dp[start][end] = min;
            }
        }
    }

    cout << dp[0][n-1];

    return 0;
}
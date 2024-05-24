/*
BackJoon No
#7579
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int memory[n];
    for(int i=0; i<n; ++i)
        cin >> memory[i];

    int cost[n];
    int sum = 0;
    for(int i=0; i<n; ++i){
        cin >> cost[i];
        sum += cost[i];
    }

    int dp[n][sum+1];
    for(int i=0; i<n; ++i){
        for(int j=0; j<=sum; ++j){
            if(i==0){
                if(j >= cost[i])
                    dp[i][j] = memory[i];
                else
                    dp[i][j] = 0;
            }else{
                if(j-cost[i] >= 0)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + memory[i]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int j=0; j<=sum; ++j){
        if(dp[n-1][j] >= m){
            cout << j;
            break;
        }
    }
    
    return 0;
}
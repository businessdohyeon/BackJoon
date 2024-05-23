/*
BackJoon No
#2293
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int input[n];
    for(int i=0; i<n; ++i)
        cin >> input[i];

    int dp[k+1];
    dp[0] = 1;
    for(int i=1; i<=k; ++i)
        dp[i] = 0;

    for(int i=0; i<n; ++i)
        for(int j=input[i]; j<=k; ++j)
            dp[j] += dp[j-input[i]];

    cout << dp[k];

    return 0;
}
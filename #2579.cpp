/*
BaekJoon No
#2579
*/

#include <iostream>
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

    int input[n];
    for(int i=0; i<n; ++i)
        cin >> input[i];

    int dp[n];
    dp[0] = input[0];
    dp[1] = input[0]+input[1];
    dp[2] = max(input[0]+input[2], input[1]+input[2]);
    for(int i=3; i<n; ++i)
        dp[i] = max(dp[i-2]+input[i], dp[i-3]+input[i-1]+input[i]);

    cout << dp[n-1];

    return 0;
}
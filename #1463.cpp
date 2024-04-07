/*
BaekJoon No
#1463
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

    int dp[n+1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4; i<=n; ++i){
        int tmp1 = i%3 == 0 ? dp[i/3] : dp[i-1];
        int tmp2 = i%2 == 0 ? dp[i/2] : dp[i-1];

        dp[i] = min(dp[i-1], min(tmp1, tmp2))+1;
    }

    cout << dp[n];

    return 0;
}
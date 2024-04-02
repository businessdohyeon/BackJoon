/*
BaekJoon No
#1904
*/

#include <iostream>

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

    int MAGIC_NUMBER = 15746;

    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; ++i)
        dp[i] = (dp[i-2] + dp[i-1]) % MAGIC_NUMBER;

    cout << dp[n];
    
    return 0;
}
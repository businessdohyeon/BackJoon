/*
BaekJoon No
#9461
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

    long long int dp[101];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<100; ++i)
        dp[i] = dp[i-3] + dp[i-2];

    int t;
    cin >> t;

    for(int i=0; i<t; ++i){
        int n;
        cin >> n;
        cout << dp[n-1] << '\n';
    }
    
    return 0;
}
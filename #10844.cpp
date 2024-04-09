/*
BaekJoon No
#10844
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
    
    int MAGIC_NUMBER = 1000000000;

    int n;
    cin >> n;

    // n번째의 마지막 수가 0~9인 경우
    int dp[n][10];

    dp[0][0] = 0;
    for(int i=1; i<10; ++i)
        dp[0][i] = 1;

    for(int i=1; i<n; ++i){
        dp[i][0] = dp[i-1][1] % MAGIC_NUMBER;
        for(int j=1; j<=8; ++j)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MAGIC_NUMBER;
        dp[i][9] = dp[i-1][8] % MAGIC_NUMBER;
    }

    int sum = 0;
    for(int i=0; i<10; ++i)
        sum = (sum+dp[n-1][i]) % 1000000000;
    cout << sum;

    return 0;
}
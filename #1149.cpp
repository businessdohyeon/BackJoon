/*
BaekJoon No
#1149
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

    int beforeMin[3] = {0, 0, 0};
    int dp[3];

    for(int i=0; i<n; ++i){
        int price[3];
        cin >> price[0] >> price[1] >> price[2];
        
        dp[0] = min(beforeMin[1], beforeMin[2]) + price[0];
        dp[1] = min(beforeMin[0], beforeMin[2]) + price[1];
        dp[2] = min(beforeMin[0], beforeMin[1]) + price[2];

        beforeMin[0] = dp[0];
        beforeMin[1] = dp[1];
        beforeMin[2] = dp[2];
    }

    int result = min(dp[0], dp[1]);
    result = min(result, dp[2]);

    cout << result;

    return 0;
}
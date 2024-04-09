/*
BaekJoon No
#2156
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

    int dp[n][2];   // 직전에 1칸인 경우, 그 외의 경우
    int max[n];     // n개일 때 최대
    for(int i=0; i<n; ++i){
        int input;
        cin >> input;

        if(i==0){
            dp[0][0] = input;
            dp[0][1] = 0;
            max[0] = dp[0][0];
        }else if(i==1){
            dp[1][0] = dp[0][0] + input;
            dp[1][1] = input;
            max[1] = dp[1][0];
        }else{
            dp[i][0] = dp[i-1][1] + input;
            dp[i][1] = max[i-2] + input;

            int bigger = dp[i][0] > dp[i][1] ? dp[i][0] : dp[i][1];
            max[i] = bigger > max[i-1] ? bigger : max[i-1];
        }
    }

    cout << max[n-1];

    return 0;
}
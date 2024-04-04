/*
BaekJoon No
#1912
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

    int dp[n];
    for(int i=0; i<n; ++i){
        int input;
        cin >> input;
        if(i==0)
            dp[i] = input;
        else
            dp[i] = dp[i-1] > 0 ? dp[i-1]+input : input;
    }

    int max = dp[0];
    for(int i=0; i<n; ++i)
        if(dp[i] > max) max = dp[i];

    cout << max;

    return 0;
}
/*
BaekJoon No
#1932
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

    int beforeDp[n];
    fill(beforeDp, beforeDp+n, 0);
    int dp[n];

    for(int i=0; i<n; ++i){
        for(int j=0; j<i+1; ++j){
            int input;
            cin >> input;

            if(j==0)
                dp[j] = beforeDp[0]+input;
            else if(j==i)
                dp[j] = beforeDp[j-1]+input;
            else
                dp[j] = max(beforeDp[j-1], beforeDp[j])+input;
        }

        for(int j=0; j<i+1; ++j)
            beforeDp[j] = dp[j];
    }

    int result = dp[0];
    for(int i=1; i<n; ++i)
        result = max(result, dp[i]);

    cout << result;

    return 0;
}
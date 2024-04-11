/*
BaekJoon No
#11053
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

    int input[n];
    for(int i=0; i<n; ++i)
        cin >> input[i];

    int dp[n];
    int max = 0;
    for(int i=0; i<n; ++i){
        int maxIdx = -1;
        for(int j=0; j<i; ++j)
            if(input[j] < input[i] && (maxIdx == -1 || dp[j] >= dp[maxIdx]))
                maxIdx = j;

        if(maxIdx == -1)
            dp[i] = 1;
        else
            dp[i] = dp[maxIdx]+1;

        if(dp[i] > max) max = dp[i];
    }
        
    cout << max;

    return 0;
}
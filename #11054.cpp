/*
BaekJoon No
#11054
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
    for(int i=0; i<n; ++i){
        int idx = -1;
        for(int j=0; j<i; ++j)
            if(input[j] < input[i] && (idx == -1 || dp[j] >= dp[idx]))
                idx = j;

        if(idx == -1)
            dp[i] = 1;
        else
            dp[i] = dp[idx]+1;
    }

    int reverseDp[n];
    for(int i=n-1; i>=0; --i){
        int idx = -1;
        for(int j=n-1; j>i; --j)
            if(input[j] < input[i] && (idx == -1 || reverseDp[j] >= reverseDp[idx]))
                idx = j;

        if(idx == -1)
            reverseDp[i] = 1;
        else
            reverseDp[i] = reverseDp[idx]+1;
    }

    int max = -1;
    for(int i=0; i<n; ++i){
        int sum = dp[i]+reverseDp[i]-1;
        if(sum > max)
            max = sum;
    }

    cout << max;

    return 0;
}
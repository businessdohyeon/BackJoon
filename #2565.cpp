/*
BaekJoon No
#2565
*/

#include <iostream>
#include <vector>
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

    vector<pair<int, int> > input;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        input.push_back(make_pair(a, b));
    }

    sort(input.begin(), input.end());
    
    int max = -1;
    int dp[n];
    for(int i=0; i<n; ++i){
        int idx = -1;
        for(int j=0; j<i; ++j)
            if(input[j].second < input[i].second && (idx==-1 || dp[j] > dp[idx]))
                idx = j;
        
        if(idx == -1)
            dp[i] = 1;
        else
            dp[i] = dp[idx]+1;

        if(dp[i] > max)
            max = dp[i];
    }

    cout << n-max;

    return 0;
}
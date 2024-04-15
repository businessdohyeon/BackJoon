/*
BaekJoon No
#12865
*/

#include <iostream>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Item{
    public:
        int weight;
        int value;
};

int main(){
    setDefault();
    
    int n, limit;
    cin >> n >> limit;

    Item input[n];
    for(int i=0; i<n; ++i)
        cin >> input[i].weight >> input[i].value;

    int dp[limit+1][n];
    for(int i=0; i<=limit; ++i){
        for(int j=0; j<n; ++j){
            int result;
            if(i==0)
                result = 0;
            else if(j==0)
                result = (input[j].weight <= i) ? input[j].value : 0;
            else if(input[j].weight > i)
                result = dp[i][j-1];
            else
                result = max(dp[i][j-1], dp[i-input[j].weight][j-1] + input[j].value);

            dp[i][j] = result;
        }
    }

    cout << dp[limit][n-1];

    return 0;
}
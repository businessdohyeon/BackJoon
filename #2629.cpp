/*
BackJoon No
#2629
*/

#include <iostream>
#include <cmath>

#define WEIGHT_MAX 30
#define BEED_MAX 40000

using namespace std;

int weightCnt;
int weight[WEIGHT_MAX];
bool dp[WEIGHT_MAX+1][BEED_MAX+1];

void setDp(int idx, int totalWeight){
    if(idx > weightCnt || dp[idx][totalWeight])     return;
    
    dp[idx][totalWeight] = true;
    setDp(idx+1, totalWeight);
    setDp(idx+1, totalWeight+weight[idx]);
    setDp(idx+1, abs(totalWeight-weight[idx]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> weightCnt;
    for(int i=0; i<weightCnt; ++i)
        cin >> weight[i];
    
    for(int i=0; i<WEIGHT_MAX; ++i)
        for(int j=0; j<BEED_MAX+1; ++j)
            dp[i][j] = false;

    setDp(0, 0);

    int beedCnt;
    cin >> beedCnt;
    for(int i=0; i<beedCnt; ++i){
        int beed;
        cin >> beed;
        if(dp[weightCnt][beed])
            cout << "Y ";
        else    
            cout << "N ";
    }

    return 0;
}
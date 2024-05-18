/*
BaekJoon No
#11066
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

    for(int trial=0; trial<n; ++trial){
        int size;
        cin >> size;

        int input[size];
        int prefixSum[size];
        for(int i=0; i<size; ++i){
            cin >> input[i];
            prefixSum[i] = i==0 ? input[i] : prefixSum[i-1]+input[i];
        }

        int dp[size][size];
        for(int idx=0; idx<size; ++idx){
            int start = 0;
            int end = idx;

            while(start<size && end<size){
                if(start == end){
                    dp[start][end] = 0;
                }else if(end == start+1){
                    dp[start][end] = input[start]+input[end];
                }else{
                    int min = -1;
                    for(int mid=start; mid<=end-1; ++mid){
                        int sum = start == 0 ? prefixSum[end] : prefixSum[end]-prefixSum[start-1];
                        int cal = dp[start][mid]+dp[mid+1][end] + sum;
                        if(min == -1 || min > cal)
                            min = cal;
                    }
                    dp[start][end] = min;
                }

                ++start;
                ++end;
            }
        }

        cout << dp[0][size-1] << '\n';
    }

    return 0;
}
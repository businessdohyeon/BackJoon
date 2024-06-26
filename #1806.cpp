/*
BackJoon No
#1806
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s;
    cin >> n >> s;

    int elems[n+1];
    for(int i=1; i<=n; ++i)
        cin >> elems[i];

    int prefixSum[n+1];
    prefixSum[0] = 0;
    for(int i=1; i<=n; ++i)
        prefixSum[i] = prefixSum[i-1]+elems[i];

    int minLen = 0;
    for(int front=0, rear=0; front<=rear && rear<=n; ){
        int cal = prefixSum[rear]-prefixSum[front];
        int len = rear-front;
        
        if(cal >= s){
            if(minLen == 0 || len < minLen)
                minLen = len;
            ++front;
        }else{
            ++rear;
        }
    }

    cout << minLen;

    return 0;
}
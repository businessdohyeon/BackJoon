/*
BackJoon No
#1644
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    bool isPrimeNumber[n+1];
    fill(isPrimeNumber, isPrimeNumber+n+1, true);
    isPrimeNumber[0] = false;
    isPrimeNumber[1] = false;

    vector<int> primeNumbers;
    for(int i=2; i<=n; ++i){
        if(isPrimeNumber[i]){
            primeNumbers.push_back(i);
            for(int j=2; i*j<=n; ++j)
                isPrimeNumber[i*j] = false;
        }
    }

    vector<int> prefixSum;
    prefixSum.push_back(0);
    for(int e : primeNumbers)
        prefixSum.push_back(e + prefixSum[prefixSum.size()-1]);

    int cnt = 0;
    int front=0, rear=0;
    while(front<=rear && rear<prefixSum.size()){
        int cal = prefixSum[rear]-prefixSum[front];
        if(cal == n){
            ++cnt;
            ++front;
            ++rear;
        }else if(cal > n){
            ++front;
        }else{
            ++rear;
        }
    }

    cout << cnt;

    return 0;
}
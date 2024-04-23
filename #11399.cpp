/*
BaekJoon No
#11399
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

    int input[n];
    for(int i=0; i<n; ++i)
        cin >> input[i];

    sort(input, input+n);

    int prefixSum[n];
    prefixSum[0] = input[0];
    for(int i=1; i<n; ++i)
        prefixSum[i] = prefixSum[i-1]+input[i];
    
    int result = 0;
    for(int i=0; i<n; ++i)
        result += prefixSum[i];

    cout << result;

    return 0;
}
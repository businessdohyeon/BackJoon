/*
BaekJoon No
#10986
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

    int size, divisor;
    cin >> size >> divisor;

    int input[size];
    for(int i=0; i<size; ++i)
        cin >> input[i];

    int prefixSum[size];
    prefixSum[0] = input[0] % divisor;
    for(int i=1; i<size; ++i)
        prefixSum[i] = (prefixSum[i-1]+input[i])%divisor;

    long long modeCntArr[divisor];
    fill(modeCntArr, modeCntArr+divisor, 0);
    for(int i=0; i<size; ++i)
        ++modeCntArr[prefixSum[i]];

    long long result = 0;
    result += modeCntArr[0];
    for(int i=0; i<divisor; ++i)
        if(modeCntArr[i] >= 2)
            result += (modeCntArr[i]*(modeCntArr[i]-1))/2;

    cout << result;

    return 0;
}
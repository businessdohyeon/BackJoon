/*
BaekJoon No
#2559
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
    
    int days, size;
    cin >> days >> size;

    int input[days];
    for (int i = 0; i < days; ++i)
        cin >> input[i];

    int cnt = days-size+1;
    int prefixSum[cnt];

    prefixSum[0] = 0;
    for(int i=0; i<size; ++i)
        prefixSum[0] += input[i];

    int max = prefixSum[0];
    for(int i=1; i<cnt; ++i){
        prefixSum[i] = prefixSum[i-1] - input[i-1] + input[i+size-1];
        if(prefixSum[i] > max)
            max = prefixSum[i];
    }

    cout << max;

    return 0;
}
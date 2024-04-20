/*
BaekJoon No
#11660
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

    int inputSize, cnt;
    cin >> inputSize >> cnt;
    
    int input[inputSize][inputSize];
    for(int i=0; i<inputSize; ++i)
        for(int j=0; j<inputSize; ++j)
            cin >> input[i][j];

    int prefixSize = inputSize +1;
    int prefixSum[prefixSize][prefixSize];
    for(int i=0; i<prefixSize; ++i)
        for(int j=0; j<prefixSize; ++j)
            if(i==0 || j==0)
                prefixSum[i][j] = 0;
            else
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + input[i-1][j-1];

    for(int i=0; i<cnt; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefixSum[x2][y2] - prefixSum[x1-1][y2] - prefixSum[x2][y1-1] + prefixSum[x1-1][y1-1] << '\n';
    }   

    return 0;
}
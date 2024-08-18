/*
BackJoon No.
#2775
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testNum;
    cin >> testNum;

    int prefix[15][15];
    for(int i=0; i<=14; ++i)
        prefix[0][i] = i;
    for(int i=1; i<=14; ++i){
        prefix[i][1] = prefix[i-1][1];
        for(int j=2; j<=14; ++j){
            prefix[i][j] = prefix[i][j-1] + prefix[i-1][j];
        }
    }

    for(int i=0; i<testNum; ++i){
        int floor, room;
        cin >> floor >> room;
        cout << prefix[floor][room] << '\n';
    }

    return 0;
}
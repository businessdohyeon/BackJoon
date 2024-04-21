/*
BaekJoon No
#25682
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

    int row, col, size;
    cin >> row >> col >> size;

    char input[row][col];
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            cin >> input[i][j];

    int whenRowStartWithBlack[row][col];
    int whenRowStartWithWhite[row][col];
    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            if(j==0){
                whenRowStartWithBlack[i][j] = input[i][j] == 'B' ? 0 : 1;
                whenRowStartWithWhite[i][j] = input[i][j] == 'W' ? 0 : 1;
            }else{
                if(j%2 == 0){
                    whenRowStartWithBlack[i][j] = whenRowStartWithBlack[i][j-1] + int(input[i][j] == 'W');
                    whenRowStartWithWhite[i][j] = whenRowStartWithWhite[i][j-1] + int(input[i][j] == 'B');
                }else{
                    whenRowStartWithBlack[i][j] = whenRowStartWithBlack[i][j-1] + int(input[i][j] == 'B');
                    whenRowStartWithWhite[i][j] = whenRowStartWithWhite[i][j-1] + int(input[i][j] == 'W');
                }
            }
        }
    }

    int prefixSum_whenFirstElementIsBlack[row][col];
    int prefixSum_whenFirstElementIsWhite[row][col];
    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            if(i==0){
                prefixSum_whenFirstElementIsBlack[i][j] = whenRowStartWithBlack[i][j];
                prefixSum_whenFirstElementIsWhite[i][j] = whenRowStartWithWhite[i][j];
            }else{
                if(i%2 == 0){
                    prefixSum_whenFirstElementIsBlack[i][j] = prefixSum_whenFirstElementIsBlack[i-1][j] + whenRowStartWithBlack[i][j];
                    prefixSum_whenFirstElementIsWhite[i][j] = prefixSum_whenFirstElementIsWhite[i-1][j] + whenRowStartWithWhite[i][j];
                }else{
                    prefixSum_whenFirstElementIsBlack[i][j] = prefixSum_whenFirstElementIsBlack[i-1][j] + whenRowStartWithWhite[i][j];
                    prefixSum_whenFirstElementIsWhite[i][j] = prefixSum_whenFirstElementIsWhite[i-1][j] + whenRowStartWithBlack[i][j];
                }
            }
        }
    }

    int min = row*col;
    for(int i=0; i<=row-size; ++i){
        for(int j=0; j<=col-size; ++j){
            int subtrahend1 = i>0 ?  prefixSum_whenFirstElementIsBlack[i-1][j+size-1] : 0;
            int subtrahend2 = j>0 ?  prefixSum_whenFirstElementIsBlack[i+size-1][j-1] : 0;
            int augend1 = i>0 && j>0 ? prefixSum_whenFirstElementIsBlack[i-1][j-1] : 0;
            int startWithBlack = prefixSum_whenFirstElementIsBlack[i+size-1][j+size-1] - subtrahend1 - subtrahend2 + augend1;

            int subtrahend3 = i>0 ?  prefixSum_whenFirstElementIsWhite[i-1][j+size-1] : 0;
            int subtrahend4 = j>0 ?  prefixSum_whenFirstElementIsWhite[i+size-1][j-1] : 0;
            int augend2 = i>0 && j>0 ? prefixSum_whenFirstElementIsWhite[i-1][j-1] : 0;
            int startWithWhite = prefixSum_whenFirstElementIsWhite[i+size-1][j+size-1] - subtrahend3 - subtrahend4 + augend2;

            int smaller = startWithBlack < startWithWhite ? startWithBlack : startWithWhite;
            if(smaller < min)       min = smaller;
        }
    }

    cout << min;

    return 0;
}
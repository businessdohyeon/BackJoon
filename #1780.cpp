/*
BaekJoon No
#1780
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int input[2187][2187];
int cnt_minusOne = 0, cnt_zero = 0, cnt_plusOne = 0;

void divideAndConquer(int startRow, int startCol, int size){
    int firstElement = input[startRow][startCol];
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            if(input[startRow+i][startCol+j] != firstElement){
                int sizeDividedBy3 = size/3;
                for(int a=0; a<3; ++a)
                    for(int b=0; b<3; ++b)
                        divideAndConquer(startRow + a*sizeDividedBy3, startCol + b*sizeDividedBy3, sizeDividedBy3);
                return;
            }
        }
    }
    
    switch(firstElement){
        case -1:
            ++cnt_minusOne;
            break;
        case 0:
            ++cnt_zero;
            break;
        case 1:
            ++cnt_plusOne;
            break;
        default:
            break;
    }
}

int main(){
    setDefault();

    int n;
    cin >> n;

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> input[i][j];

    divideAndConquer(0, 0, n);

    cout << cnt_minusOne << '\n' << cnt_zero << '\n' << cnt_plusOne;
    
    return 0;
}
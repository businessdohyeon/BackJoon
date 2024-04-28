/*
BaekJoon No
#2630
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool inputs[128][128];
int white = 0;
int blue = 0;

void divideAndConquer(int startRow, int startCol, int size){
    bool flag = true;
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            if(inputs[startRow+i][startCol+j] != inputs[startRow][startCol]){
                flag = false;
                break;
            }
        }
    }

    if(flag){
        if(inputs[startRow][startCol])  ++blue;
        else                            ++white;
    }else{
        int halfedSize = size/2;
        divideAndConquer(startRow, startCol, halfedSize);
        divideAndConquer(startRow + halfedSize, startCol, halfedSize);
        divideAndConquer(startRow, startCol + halfedSize, halfedSize);
        divideAndConquer(startRow + halfedSize, startCol + halfedSize, halfedSize);
    }
}

int main(){
    setDefault();

    int n;
    cin >> n;

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> inputs[i][j];

    divideAndConquer(0, 0, n);

    cout << white << '\n' << blue;

    return 0;
}
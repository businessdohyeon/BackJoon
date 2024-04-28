/*
BaekJoon No
#1992
*/

#include <iostream>
#include <string>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

char input[64][64];
string result = "";

void divideAndConquer(int startRow, int startCol, int size){
    char firstElement = input[startRow][startCol];
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            if(input[startRow+i][startCol+j] != firstElement){
                result += '(';

                int halfedsize = size/2;
                divideAndConquer(startRow, startCol, halfedsize);
                divideAndConquer(startRow, startCol+halfedsize, halfedsize);
                divideAndConquer(startRow+halfedsize, startCol, halfedsize);
                divideAndConquer(startRow+halfedsize, startCol+halfedsize, halfedsize);
                
                result += ')';
                return;
            }
        }
    }

    result += firstElement;
}

int main(){
    setDefault();

    int n;
    cin >> n;

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> input[i][j];

    divideAndConquer(0, 0, n);

    cout << result;

    return 0;
}
/*
BaekJoon No
#2740
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

    int a_height, a_width;
    cin >> a_height >> a_width;
    
    int matrixA[a_height][a_width];
    for(int i=0; i<a_height; ++i)
        for(int j=0; j<a_width; ++j)
            cin >> matrixA[i][j];

    int b_height, b_width;
    cin >> b_height >> b_width;

    int matrixB[b_height][b_width];
    for(int i=0; i<b_height; ++i)
        for(int j=0; j<b_width; ++j)
            cin >> matrixB[i][j];

    int c_height = a_height, c_width = b_width;
    int matrixC[c_height][c_width];
    for(int i=0; i<c_height; ++i){
        for(int j=0; j<c_width; ++j){
            int dotProducted = 0;
            for(int tmp=0; tmp<a_width; ++tmp)
                dotProducted += matrixA[i][tmp]*matrixB[tmp][j];
            matrixC[i][j] = dotProducted;
        }
    }

    for(int i=0; i<c_height; ++i){
        for(int j=0; j<c_width; ++j){
            cout << matrixC[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
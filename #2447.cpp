/*
BaekJoon No
#2447
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void fillStars(char** stars, int startRow, int startCol, int size){
    if(size <3) return;

    int dividedBy3 = size/3;

    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){

            if(i==1 && j==1){
                int firstRow = startRow + dividedBy3;
                int firstCol = startCol + dividedBy3;

                for(int a=0; a<dividedBy3; ++a)
                    for(int b=0; b<dividedBy3; ++b)
                        stars[firstRow+a][firstCol+b] = ' ';
            }else{
                fillStars(stars, startRow+i*dividedBy3, startCol+j*dividedBy3, dividedBy3);
            }

        }
    }
}


int main(){
    setDefault();

    int n;
    cin >> n;

    char** stars = (char**)malloc(n*sizeof(char*));
    if(stars == nullptr)    return -1;
    for(int i=0; i<n; ++i){
        stars[i] = (char*)malloc(n*sizeof(char));
        if(stars[i] == nullptr)    return -1;
    }

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            stars[i][j] = '*';

    fillStars(stars, 0, 0, n);

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << stars[i][j];
        }
        cout << '\n';
        free(stars[i]);
    }
    free(stars);

    return 0;
}
/*
BaekJoon No
#11444
*/

#include <iostream>
#include <vector>

#define NUM 1000000007
#define SIZE 2

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

typedef vector<vector<long long> > Matrix;

Matrix makeMatrix(){
    Matrix result(SIZE, vector<long long>(SIZE));
    return result;
}

Matrix multiply(Matrix a, Matrix b){
    Matrix result = makeMatrix();
    for(int i=0; i<SIZE; ++i){
        for(int j=0; j<SIZE; ++j){
            int value = 0;
            for(int tmp=0; tmp<SIZE; ++tmp)
                value = (value + a[i][tmp]*b[tmp][j])%NUM;
            result[i][j] = value;
        }
    }
    return result;
}

Matrix power(Matrix matrix, long long exponent){
    if(exponent == 1){
        return matrix;
    }else if(exponent%2==0){
        Matrix squareRoot = power(matrix, exponent/2);
        return multiply(squareRoot, squareRoot);
    }else{
        return multiply(power(matrix, exponent-1), matrix);
    }
}

int main(){
    setDefault();

    long long n;
    cin >> n;

    Matrix preset = makeMatrix();
    preset[0][0] = 0;
    preset[0][1] = 1;
    preset[1][0] = 1;
    preset[1][1] = 2;

    if(n<4){
        cout << preset[n/SIZE][n%SIZE];
    }else{
        Matrix multiplicant = makeMatrix();
        multiplicant[0][0] = 0;
        multiplicant[0][1] = 1;
        multiplicant[1][0] = 1;
        multiplicant[1][1] = 1;

        Matrix powerd = power(multiplicant, n-3);
        Matrix result = multiply(preset, powerd);

        cout << result[1][1];
    }

    return 0;
}
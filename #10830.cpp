/*
BaekJoon No
#10830
*/

#include <iostream>
#include <vector>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

typedef vector<vector<int> > Matrix;

Matrix makeMatrix(int size){
    Matrix result(size, vector<int>(size));
    return result;
}

Matrix multiply(Matrix a, Matrix b){
    int size = a.size();
    Matrix result = makeMatrix(size);

    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            int value = 0;
            for(int tmp=0; tmp<size; ++tmp)
                value = (value + a[i][tmp]*b[tmp][j])%1000;
            result[i][j] = value;
        }
    }

    return result;
}

Matrix power(Matrix matrix, long long exponent){
    if(exponent == 1){
        return matrix;
    }else if(exponent%2 == 0){
        Matrix tmp = power(matrix, exponent/2);
        return multiply(tmp, tmp);
    }else{
        Matrix tmp = power(matrix, exponent-1);
        return multiply(tmp, matrix);
    }
}

int main(){
    setDefault();

    int size;
    long long exponent;
    cin >> size >> exponent;

    Matrix matrix = makeMatrix(size);
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            cin >> matrix[i][j];

    Matrix result = power(matrix, exponent);

    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j)
            cout << result[i][j]%1000 << ' ';
        cout << '\n';
    }

    return 0;
}
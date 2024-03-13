/*
BaekJoon No
#11050
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int factorial(int n){
    if(n==0)    return 1;
    else        return n*factorial(n-1);
}

int binomialCoefficient(int n, int k){
    return factorial(n)/factorial(k)/factorial(n-k);
}

int main(){
    setDefault();

    int n, k;
    cin >> n >> k;

    cout << binomialCoefficient(n, k);

    return 0;
}
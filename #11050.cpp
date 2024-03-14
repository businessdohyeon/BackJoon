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

unsigned long long factorial(int n){
    if(n==0)    return 1;
    else        return n*factorial(n-1);
}

unsigned long long binomialCoefficient(int n, int k){
    if(k > n/2) return binomialCoefficient(n, n-k);

    unsigned long long result = 1;
    for(int i=n; i>n-k; --i)
        result *= i;
    result /= factorial(k);

    return result;
}

int main(){
    setDefault();

    int t, n, m;
    cin >> t;

    for(int i=0; i<t; ++i){
        cin >> n >> m;
        cout << binomialCoefficient(m, n) << '\n';
    }

    return 0;
}
/*
BaekJoon No
#11401
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

long long moduledFactorial(int n, int divisor){
    long long result = 1;
    for(int i=1; i<=n; ++i)
        result = (result * i) % divisor;
    return result;
}

long long moduledPower(long long n, int exponent, int divisor){
    if(exponent == 0){
        return 1;
    }else if(exponent%2 == 0){
        long long tmp = moduledPower(n, exponent/2, divisor);
        return (tmp*tmp) % divisor;
    }else{
        return (n * moduledPower(n, exponent-1, divisor)) % divisor;
    }
}

int main(){
    setDefault();

    int NUM = 1000000007;

    int n, k;
    cin >> n >> k;

    long long term1 = moduledFactorial(n, NUM);
    long long tmp = (moduledFactorial(n-k, NUM) * moduledFactorial(k, NUM)) % NUM;
    long long term2 = moduledPower(tmp, NUM-2, NUM);
    long long result = (term1*term2) % NUM;

    cout << result;

    return 0;
}
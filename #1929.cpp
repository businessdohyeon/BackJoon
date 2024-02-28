/*
BaekJoon No
#1929
*/

#include <iostream>
#include <cmath>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool isPrimeNumber(long long n){
    if(n == 0 || n == 1)    return false;

    long long sqrtN = sqrt(n);
    for(long long i=2; i<=sqrtN; ++i)
        if(n%i == 0)        return false;

    return true;
}

int main(){
    setDefault();

    int a, b;
    cin >> a >> b;

    int is_NOT_PrimeNumber[b+1] = {0};
    for(int i=0; i<=b; ++i){
        if(is_NOT_PrimeNumber[i] == 1)  continue;

        if(isPrimeNumber(i)){
            for(int j=2; i*j<=b; ++j)
                is_NOT_PrimeNumber[i*j] = 1;
        }else{
            is_NOT_PrimeNumber[i] = 1;
        }
    }

    for(int i=a; i<=b; ++i)
        if(!is_NOT_PrimeNumber[i])
            cout << i << '\n';

    return 0;
}
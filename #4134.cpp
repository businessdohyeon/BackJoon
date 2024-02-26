/*
BaekJoon No
#4134
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

    long long n;
    cin >> n;

    for(long long i=0; i<n; ++i){
        long long input;
        cin >> input;

        long long result = input;
        while(!isPrimeNumber(result))   ++result;
        cout << result << '\n';
    }

    return 0;
}
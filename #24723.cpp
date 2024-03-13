/*
BaekJoon No
#24723
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

int main(){
    setDefault();

    int n;
    cin >> n;

    cout << factorial(n);

    return 0;
}
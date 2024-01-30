/*
BaekJoon No
#24266
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    long long n;
    cin >> n;

    cout << n*n*n << "\n3";

    return 0;
}
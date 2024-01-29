/*
BaekJoon No
#24267
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

    cout << (n-2)*(n-1)*n/6 << "\n3";

    return 0;
}
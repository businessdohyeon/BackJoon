/*
BackJoon No.
#2609
*/

#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int gcdResult = gcd(a, b);
    int lcmResult = a * b / gcdResult;

    cout << gcdResult << '\n';
    cout << lcmResult;

    return 0;
}
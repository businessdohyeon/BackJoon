/*
BaekJoon No
#13241
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

long long gcd(int a, int b){
    long long remainder = a % b;
    if(remainder == 0)  return b;
    else                return gcd(b, remainder);
}

int main(){
    setDefault();

    long long a, b;
    cin >> a >> b;

    cout << a*b / gcd(a,b);

    return 0;
}
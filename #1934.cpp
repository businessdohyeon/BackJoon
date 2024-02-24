/*
BaekJoon No
#1934
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int gcd(int a, int b){
    int remainder = a % b;
    if(remainder == 0)  return b;
    else                return gcd(b, remainder);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        cout << a*b / gcd(a,b) << '\n';
    }

    return 0;
}
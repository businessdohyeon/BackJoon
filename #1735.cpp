/*
BaekJoon No
#1735
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

    int a_top, a_bottom, b_top, b_bottom;
    cin >> a_top >> a_bottom >> b_top >> b_bottom;

    int raw_top = a_top*b_bottom + b_top*a_bottom;
    int raw_bottom = a_bottom*b_bottom;

    int gcd_for_raw = gcd(raw_top, raw_bottom);
    int simplified_top = raw_top / gcd_for_raw;
    int simplified_bottom = raw_bottom / gcd_for_raw;

    cout << simplified_top << ' ' << simplified_bottom;

    return 0;
}
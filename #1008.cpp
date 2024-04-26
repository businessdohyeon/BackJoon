/*
BaekJoon No
#1008
*/

#include <iostream>
#include <iomanip>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    long double a, b, result;
    cin >> a >> b;
    result = a / b;
    cout << setprecision(10) << result;

    return 0;
}
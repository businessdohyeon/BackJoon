/*
BaekJoon No
#10430
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    int a, b, c;
    cin >> a >> b >> c;

    cout << (a+b)%c << '\n';
    cout << ((a%c)+(b%c))%c << '\n';
    cout << (a*b)%c << '\n';
    cout << ((a%c)*(b%c))%c << '\n';

    return 0;
}
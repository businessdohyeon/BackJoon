/*
BaekJoon No
#10998
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

    int a, b;
    cin >> a >> b;
    cout << a*b;

    return 0;
}
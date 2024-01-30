/*
BaekJoon No
#27323
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int a, b;
    cin >> a >> b;
    cout << a*b;

    return 0;
}
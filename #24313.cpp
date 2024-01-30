/*
BaekJoon No
#24313
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    int result;
    result = (c >= a1) && (a0 <= (c - a1) * n0);

    cout << result;

    return 0;
}
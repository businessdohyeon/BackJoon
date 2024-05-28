/*
BackJoon No.
#2588
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    for(int i=1; b/i > 0; i *= 10)
        cout << a * (b/i%10) << endl;
    cout << a*b;

    return 0;
}
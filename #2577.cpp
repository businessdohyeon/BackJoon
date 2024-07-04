/*
BackJoon No.
#2577
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    
    int cal = a*b*c;

    int s[10] = {0, };
    while(cal > 0){
        ++s[cal%10];
        cal /= 10;
    }

    for(int i=0; i<=9; ++i)
        cout << s[i] << '\n';

    return 0;
}
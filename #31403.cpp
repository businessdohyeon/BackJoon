/*
BackJoon No.
#31403
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    cout << a+b-c << '\n';

    for(int tmp=b; tmp>0; tmp/=10, a*=10);

    cout << a+b-c << '\n';

    return 0;
}
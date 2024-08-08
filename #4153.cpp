/*
BackJoon No.
#4153
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true){
        long long a, b, c;
        cin >> a >> b >> c;

        if(a == 0 && b == 0 && c == 0)  break;

        if(pow(a, 2)+pow(b, 2)+pow(c, 2) == 2*pow(max(a, max(b, c)), 2))
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
    }

    return 0;
}
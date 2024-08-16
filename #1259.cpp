/*
BackJoon No.
#1259
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true){
        int n;
        cin >> n;

        if(n == 0)  break;

        int digit = 0;
        for(int tmp=n; tmp>0; tmp/=10, ++digit);

        bool isPalendrome = true;
        for(int i=0; i<digit/2; ++i)
            if(int(n / pow(10, i)) % 10 != int(n / pow(10, digit-i-1)) % 10)
                isPalendrome = false;

        if(isPalendrome)    cout << "yes" << '\n';
        else                cout << "no" << '\n';
    }

    return 0;
}
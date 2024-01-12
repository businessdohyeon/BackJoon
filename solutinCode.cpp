/*
BaekJoon No
#2720
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int t;
    cin >> t;

    for(int i=0; i < t; ++i){
        int q = 0, d = 0, n = 0, p = 0; //25, 10, 5, 1
        int num;

        cin >> num;

        for(; num - 25 >= 0; ++q)   num -= 25;
        for(; num - 10 >= 0; ++d)   num -= 10;
        for(; num - 5 >= 0; ++n)   num -= 5;
        for(; num - 1 >= 0; ++p)   num -= 1;

        cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';
    }
    
    return 0;
}
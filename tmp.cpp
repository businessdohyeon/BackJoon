#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i=0; i < t; ++i){
        int q = 0, d = 0, n = 0, p = 0; //25, 10, 5, 1
        int num;

        cin >> num;

        while(num - 25 >= 0){
            num -= 25;
            ++q;
        }
        while(num - 10 >= 0){
            num -= 10;
            ++d;
        }
        while(num - 5 >= 0){
            num -= 5;
            ++n;
        }
        while(num - 1 >= 0){
            num -= 1;
            ++p;
        }

        cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';
    }

    
    return 0;
}
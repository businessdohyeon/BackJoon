/*
BaekJoon No
#19532
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int a, b, c, d, e ,f;
    cin >> a >> b >> c >> d >> e >> f;

    for(int x = -999; x <= 999; ++x){
        for(int y = -999; y <= 999; ++y){
            if(a*x + b*y == c && d*x + e*y == f){
                cout << x << ' ' << y;
                break;
            }
        }
    }

    return 0;
}
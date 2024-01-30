/*
BaekJoon No
#14215
*/

#include <iostream>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int a, b ,c;
    cin >> a >> b >> c;

    int result;
    if(2*max({a,b,c}) < a+b+c)  result = a+b+c;
    else                        result =  2 * (a+b+c - max({a,b,c})) - 1;

    cout << result;

    return 0;
}
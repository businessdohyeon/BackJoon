/*
BaekJoon No
#5073
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    while(true){
        int a, b, c;
        cin >> a >> b >> c;
        if(!a && !b && !c)  break;

        string result;
        if(a+b+c <= 2*max({a,b,c}))     result = "Invalid";
        else if(a==b && b==c && c==a)   result = "Equilateral";
        else if(a!=b && b!=c && c!=a)   result = "Scalene";
        else                            result = "Isosceles";
        
        cout << result << '\n';
    }

    return 0;
}
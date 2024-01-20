/*
BaekJoon No
#2581
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

bool isDecimal(int n){
    if(n == 1)  return false;

    bool result = true;
    for(int i=2; i<n; ++i){
        if(n%i ==0){
            result = false;
            break;
        }
    }
    return result;
}

int main(){
    setDefault();

    int a, b;
    cin >> a >> b;

    int min = -1;
    int sum = 0;
    for(int i=a; i<=b; ++i){
        if(isDecimal(i)){
            if(min == -1)   min = i;
            sum += i;
        }
    }

    if(min == -1)   cout << min;
    else            cout << sum << '\n' << min;

    return 0;
}
/*
BaekJoon No
#1978
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

    int n;
    cin >> n;

    int cnt = 0;

    for(int i=0; i<n; ++i){
        int tmp;
        cin >> tmp;
        if(isDecimal(tmp)){
            ++cnt;
        }
    }

    cout << cnt;

    return 0;
}
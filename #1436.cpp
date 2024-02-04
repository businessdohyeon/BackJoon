/*
BaekJoon No
#1436
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

bool isDoomNumber(int n){
    int cnt = 0;
    while(n>0){
        int lastNumber = n%10;
        if(lastNumber == 6){
            ++cnt;
            if(cnt == 3)    return true;
        }else{
            cnt = 0;
        }
        n /= 10;
    }
    return false;
}

int main(){
    setDefault();

    int n;
    cin >> n;

    int cnt = 0;
    int result = 665;
    while(cnt < n){
        ++result;
        if(isDoomNumber(result))    ++cnt;
    }

    cout << result;

    return 0;
}
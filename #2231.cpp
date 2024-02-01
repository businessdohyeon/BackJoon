/*
BaekJoon No
#2231
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int cal(int n){
    int sum = n;
    while(n!=0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(){
    setDefault();

    int n;
    cin >> n;

    int result = 0;
    int max = cal(999999);
    for(int i=1; i<max; ++i){
        if(cal(i) == n){
            result = i;
            break;
        }
    }
    cout << result;

    return 0;
}
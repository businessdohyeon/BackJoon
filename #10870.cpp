/*
BaekJoon No
#10870
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int fibonacci(int n){
    if(n==0)    return 0;
    if(n==1)    return 1;
    else        return fibonacci(n-2)+fibonacci(n-1);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    cout << fibonacci(n);    

    return 0;
}
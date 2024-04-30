/*
BaekJoon No
#1629
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

long long divideAndConquer(int a, int b, int c){
    if(b==0){
        return 1;
    }else if(b%2 == 0){
        long long halfPowed = divideAndConquer(a, b/2, c);
        return halfPowed*halfPowed % c;
    }else{
        return a * divideAndConquer(a, b-1, c) % c;
    }
}

int main(){
    setDefault();

    int a, b, c;
    cin >> a >> b >> c;

    cout << divideAndConquer(a%c, b, c);

    return 0;
}
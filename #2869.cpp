/*
BaekJoon No
#2869
*/

#include <iostream>
#include <cmath>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int a, b, v;
    cin >> a >> b >> v;

    int result = ceil(1.0 * (v-b) / (a-b));

    cout << result;

    // a * cnt - b *(cnt-1) >= v
    // (a-b) * cnt +b >= v
    // (a-b) * cnt >= v -b
    // cnt >= (v-b)/(a-b) 를 만족하는 최소한의 자연수

    return 0;
}
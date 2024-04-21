/*
BaekJoon No
#11074
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    int n, k;
    cin >> n >> k;

    int input[n];
    for(int i=0; i<n; ++i)
        cin >> input[i];

    int cnt = 0;
    for(int i=n-1; i>=0; --i){
        if(input[i] <= k){
            int tmp = k / input[i];
            k -= tmp * input[i];
            cnt += tmp;
        }
    }
    cout << cnt;

    return 0;
}
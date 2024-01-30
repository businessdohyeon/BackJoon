/*
BaekJoon No
#2501
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int n, k;
    cin >> n >> k;

    int cnt = 0;

    int result = 0;

    for(int i=1; i<=n; ++i){
        if(n%i == 0){
            ++cnt;
            if(cnt == k){
                result = i;
                break;
            }
        }
    }
    
    cout << result;

    return 0;
}
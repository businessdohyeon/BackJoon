/*
BaekJoon No
#2839
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    int result = -1;
    for(int i=0; i <= n/5; ++i){
        for(int j=0; j <= n/3; ++j){
            if(5*i + 3*j == n){
                result = i+j;
                break;
            }
        }
    }
    
    cout << result;

    return 0;
}
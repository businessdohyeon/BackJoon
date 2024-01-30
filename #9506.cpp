/*
BaekJoon No
#9506
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    while(true){
        int n;
        cin >> n;

        if(n== -1)  break;

        int s[100000] = {0};
        int sum = 0;
        int cnt = 0;

        for(int i=1; i < n; ++i){
            if(n%i == 0){
                s[cnt] = i;
                sum += i;
                ++cnt;
            }
        }
        
        if(sum == n){
            cout << n << " = " << s[0];
            for(int i=1; i<cnt; ++i)    cout << " + " << s[i];
            cout << '\n';
        }else{
            //case1
            cout << n << " is NOT perfect.\n";

            //case2
            // cout << n << " is NOT perfect.";
            // cout << '\n';
        }
    }

    return 0;
}
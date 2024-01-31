/*
BaekJoon No
#2798
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int n, m;
    cin >> n >> m;
    
    int s[n];
    for(int i=0; i < n; ++i)
        cin >> s[i];
    
    int max = 0;
    for(int i=0; i < n-2; ++i){
        for(int j=i+1; j < n-1; ++j){
            for(int k=j+1; k < n; ++k){
                int sum = s[i] + s[j] + s[k];
                if(sum <= m && sum > max)   max = sum;
            }
        }
    }
    cout << max;

    return 0;
}
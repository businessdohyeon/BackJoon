/*
BaekJoon No
#2750
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

    int s[n];
    for(int i=0; i<n; ++i)
        cin >> s[i];
    
    for(int i=0; i<n-1; ++i){
        for(int j=i+1; j < n; ++j){
            if(s[i] > s[j]){
                int tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
    
    for(int i=0; i<n; ++i)
        cout << s[i] << '\n';

    return 0;
}
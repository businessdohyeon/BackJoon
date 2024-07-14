/*
BackJoon No.
#1032
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);#1032
    cout.tie(nullptr);

    int n;
    cin >> n;

    string s[n];
    for(int i=0; i<n; ++i)
        cin >> s[i];

    string ans;
    for(int i=0; i<s[0].length(); ++i){
        bool isCommon = true;
        for(int j=1; j<n; ++j){
            if(s[j][i] != s[0][i]){
                isCommon = false;
                break;
            }
        }
        if(isCommon)    ans += s[0][i];
        else            ans += '?';
    }

    cout << ans;

    return 0;
}
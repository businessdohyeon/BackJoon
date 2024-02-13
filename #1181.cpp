/*
BaekJoon No
#1181
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

bool comp(string a, string b){
    int a_len = a.length();
    int b_len = b.length();
    if(a_len == b_len)      return a < b;
    else                    return a_len < b_len;
}

int main(){
    setDefault();

    int n;
    cin >> n;

    string s[n];
    for(int i=0; i<n; ++i)
        cin >> s[i];
    
    sort(s, s+n, comp);

    for(int i=0; i<n; ++i){
        bool isRepeated = false;
        for(int j=0; j<i; ++j){
            if(s[i] ==s[j]){
                isRepeated = true;
                break;
            }
        }
        if(isRepeated)  continue;
        
        cout << s[i] << '\n';
    }

    return 0;
}
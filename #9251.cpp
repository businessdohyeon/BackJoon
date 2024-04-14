/*
BaekJoon No
#9251
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();
    
    string a, b;
    cin >> a >> b;

    int a_len = a.length();
    int b_len = b.length();
    int lcs[a_len+1][b_len+1];
    int result = -1;
    for(int i=0; i<a_len+1; ++i){
        for(int j=0; j<b_len+1; ++j){
            if(i==0 || j==0)
                lcs[i][j] = 0;
            else if(a[i-1] == b[j-1])
                lcs[i][j] = lcs[i-1][j-1]+1;
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);

            if(lcs[i][j] > result)
                result = lcs[i][j];
        }
    }

    cout << result;

    return 0;
}
/*
BackJoon No.
#1100
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char s[8][8];
    for(int i=0; i<8; ++i)
        for(int j=0; j<8; ++j)
            cin >> s[i][j];

    int ans = 0;
    for(int i=0; i<8; ++i)
        for(int j=0; j<8; ++j)
            if(s[i][j] == 'F' && (i+j) % 2 == 0)
                ++ans;

    cout << ans;

    return 0;
}
/*
BackJoon No.
#6840
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s[3];
    for(int i=0; i<3; ++i)
        cin >> s[i];

    sort(s, s+3);

    cout << s[1];

    return 0;
}
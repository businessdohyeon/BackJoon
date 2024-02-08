/*
BaekJoon No
#2751
*/

#include <iostream>
#include <algorithm>

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

    sort(s, s+n);

    for(int i=0; i<n; ++i)
        cout << s[i] << '\n';

    return 0;
}
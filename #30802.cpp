/*
BackJoon No.
#30802
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int shirt[6];
    for(int i=0; i<6; ++i)
        cin >> shirt[i];

    int t, p;
    cin >> t >> p;

    int ans = 0;
    for(int i=0; i<6; ++i)
        ans += int((shirt[i]+t-1)/t);

    cout << ans << '\n';
    cout << int(n/p) << ' ' << int(n%p);

    return 0;
}
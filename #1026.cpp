/*
BackJoon No.
#1026
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int a[n], b[n];
    for(int i=0; i<n; ++i)
        cin >> a[i];
    for(int i=0; i<n; ++i)
        cin >> b[i];

    sort(a, a+n);
    sort(b, b+n, greater<int>());

    int ans = 0;
    for(int i=0; i<n; ++i)
        ans += a[i]*b[i];

    cout << ans;

    return 0;
}
/*
BackJoon No.
#1075
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, f;
    cin >> n >> f;

    int cal = abs(f - n/100 * 100 % f) % f;
    string ans = to_string(cal);
    while(ans.size() < 2)
        ans = '0' + ans;

    cout << ans;

    return 0;
}
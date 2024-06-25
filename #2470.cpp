/*
BackJoon No.
#2470
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int s[n];
    for(int i=0; i<n; ++i)
        cin >> s[i];

    sort(s, s+n);

    int ans1 = 1000000000, ans2 = 1000000000;
    for(int front=0, rear=n-1; front<rear; ){
        int cal = s[front]+s[rear];

        if(abs(cal) < abs(ans1+ans2)){
            ans1 = s[front];
            ans2 = s[rear];
        }

        if(cal == 0)        break;
        else if(cal > 0)    --rear;
        else                ++front;
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}
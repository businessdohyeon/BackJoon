/*
BackJoon No.
#3273
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

    int s[n];
    for(int i=-0; i<n; ++i)
        cin >> s[i];

    int x;
    cin >> x;

    sort(s, s+n);

    int cnt = 0;
    int front = 0, rear = n-1;
    while(front < rear){
        int cal = s[front]+s[rear];
        if(cal == x){
            ++cnt;
            ++front;
            --rear;
        }else if(cal > x){
            --rear;
        }else{
            ++front;
        }
    }

    cout << cnt;

    return 0;
}
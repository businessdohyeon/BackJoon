/*
BackJoon No.
#13913
*/

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int RANGE_MAX = 100000;

    int n, k;
    cin >> n >> k;

    if(n >= k){
        cout << n-k << '\n';
        for(int i=n; i>=k; --i)
            cout << i << ' ';
        return 0;
    }

    int prev[RANGE_MAX+1];
    fill(prev, prev+RANGE_MAX+1, -1);
    prev[n] = -2;

    deque<int> dq;
    dq.push_back(n);
    while(!dq.empty()){
        int front = dq.front();
        dq.pop_front();

        if(front == k)  break;

        for(const int& next : {front-1, front+1, 2*front}){
            if(next<0 || next>RANGE_MAX || prev[next] != -1)   continue;
            prev[next] = front;
            dq.push_back(next);
        }
    }

    deque<int> path;
    for(int i=k; i != n; i = prev[i])
        path.push_front(i);
    path.push_front(n);

    cout << path.size()-1 << '\n';
    for(const int& e : path)
        cout << e << ' ';

    return 0;
}
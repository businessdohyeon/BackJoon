/*
BackJoon No.
#1697
*/

#include <iostream>
#include <deque>

using namespace std;

const int MAX = 100001;

int n, k;
bool visited[MAX];
int cnt;
int ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    deque<int> dq1, dq2;
    dq1.push_back(n);

    deque<int> *cur = &dq1, *next = &dq2;
    while(!cur->empty()){
        int front = cur->front();
        cur->pop_front();

        visited[front] = true;
        if(front == k){
            ans = cnt;
            break;
        }

        int paths[] = {front-1, front+1, 2*front};
        for(auto path : paths)
            if(path >= 0 && path < MAX && !visited[path])
                next->push_back(path);

        if(cur->empty()){
            swap(cur, next);
            ++cnt;
        }
    }

    cout << ans;

    return 0;
}
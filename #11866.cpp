/*
BaekJoon No
#11866
*/

#include <iostream>
#include <queue>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    int n, k;
    cin >> n >> k;

    queue<int> q;
    for(int i=1; i<=n; ++i)
        q.push(i);
    
    int cnt = 1;
    while(!q.empty()){
        if(cnt == k){
            cout << q.front();
            q.pop();
            if(q.size() != 1){
                cout << ", ";
            }
            cnt = 1;
        }else{
            q.push(q.front());
            q.pop();
            ++cnt;
        }
    }

    return 0;
}
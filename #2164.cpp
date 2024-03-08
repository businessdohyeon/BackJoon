/*
BaekJoon No
#2164
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

    int n;
    cin >> n;

    queue<int> q;
    for(int i=1; i<=n; ++i)
        q.push(i);

    while(q.size() > 1){
        q.pop();
        if(q.size() == 1)   break;
        q.push(q.front());
        q.pop();
    }

    cout << q.front() << endl;

    return 0;
}
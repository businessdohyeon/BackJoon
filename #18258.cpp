/*
BaekJoon No
#18258
*/

#include <iostream>
#include <string>
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
    for(int i=0; i<n; ++i){
        string input;
        cin >> input;
        if(input == "push"){
            int n;
            cin >> n;
            q.push(n);
        }else if(input == "pop"){
            if(q.empty()){
                cout << -1 << '\n';
            }else{
                cout << q.front() << '\n';
                q.pop();
            }
        }else if(input == "size"){
            cout << q.size() << '\n';
        }else if(input == "empty"){
            cout << q.empty() << '\n';
        }else if(input == "front"){
            if(q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
        }else if(input == "back"){
            if(q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
        }
    }

    return 0;
}
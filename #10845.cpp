/*
BackJoon No.
#10845
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int commandNum;
    cin >> commandNum;

    queue<int> q;
    for (int i=0; i<commandNum; ++i){
        string command;
        cin >> command;

        if(command == "push"){
            int n;
            cin >> n;
            q.push(n);
        }else if(command == "pop"){
            if(q.empty()){
                cout << -1 << '\n';
            }else{
                cout << q.front() << '\n';
                q.pop();
            }
        }else if(command == "size"){
            cout << q.size() << '\n';
        }else if(command == "empty"){
            cout << int(q.empty()) << '\n';
        }else if(command == "front"){
            if(q.empty()){
                cout << -1 << '\n';
            }else{
                cout << q.front() << '\n';
            }
        }else if(command == "back"){
            if(q.empty()){
                cout << -1 << '\n';
            }else{
                cout << q.back() << '\n';
            }
        }else{
            // do nothin
        }
    }

    return 0;
}
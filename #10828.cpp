/*
BackJoon No.
#10828
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int commandNum;
    cin >> commandNum;

    stack<int> s;
    for(int i=0; i<commandNum; ++i){
        string command;
        cin >> command;
        if(command == "push"){
            int n;
            cin >> n;
            s.push(n);
        }else if(command == "pop"){
            if(s.empty()){
                cout << -1 << '\n';
            }else{
                cout << s.top() << '\n';
                s.pop();
            }
        }else if(command == "size"){
            cout << s.size() << '\n';
        }else if(command == "empty"){
            cout << int(s.empty()) << '\n';
        }else if(command == "top"){
            if(s.empty())   cout << -1 << '\n';
            else            cout << s.top() << '\n';
        }else{
            // do nothin'
        }
    }

    return 0;
}
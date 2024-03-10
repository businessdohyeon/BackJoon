/*
BaekJoon No
#28279
*/

#include <iostream>
#include <deque>

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

    deque<int> data;

    for(int i=0; i<n; ++i){
        int command, input;
        cin >> command;

        switch(command){
            case 1:
                cin >> input;
                data.push_front(input);
                break;
            case 2:
                cin >> input;
                data.push_back(input);
                break;
            case 3:
                if(data.empty()){
                    cout << -1 << '\n';
                    break;
                }
                cout << data.front() << '\n';
                data.pop_front();
                break;
            case 4:
                if(data.empty()){
                    cout << -1 << '\n';
                    break;
                }
                cout << data.back() << '\n';
                data.pop_back();
                break;
            case 5:
                cout << data.size() << '\n';
                break;
            case 6:
                cout << (int)data.empty() << '\n';
                break;
            case 7:
                if(data.empty()){
                    cout << -1 << '\n';
                    break;
                }
                cout << data.front() << '\n';
                break;
            case 8:
                if(data.empty()){
                    cout << -1 << '\n';
                    break;
                }
                cout << data.back() << '\n';
                break;
            default:
                break;
        }
    }

    return 0;
}
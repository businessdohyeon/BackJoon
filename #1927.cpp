/*
BaekJoon No
#1927
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
    
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; ++i){
        int command;
        cin >> command;

        if(command > 0){
            pq.push(command);
        }else{
            if(pq.empty()){
                cout << 0 << '\n';
            }else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
    
    return 0;
}
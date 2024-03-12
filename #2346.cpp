/*
BaekJoon No
#2346
*/

#include <iostream>
#include <deque>
#include <vector>

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

    deque<int> dq;
    for(int i=1; i<=n; ++i)
        dq.push_back(i);

    vector<int> value;
    for(int i=0; i<n; ++i){
        int input;
        cin >> input;
        value.push_back(input);
    }

    while(!dq.empty()){
        int target = dq.front();
        cout << target << ' ';
        dq.pop_front();

        int targetValue = value[target-1];

        if(targetValue > 0){
            for(int i=0; i<targetValue-1; ++i){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else{
            for(int i=0; i<(-1)*targetValue; ++i){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}
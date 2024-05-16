/*
BaekJoon No
#11286
*/

#include <iostream>
#include <queue>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct cmp{
    bool operator()(int a, int b){
        int abs_a = a > 0 ? a : -a;
        int abs_b = b > 0 ? b : -b;
        if(abs_a == abs_b)
            return a > b;
        return abs_a > abs_b;
    }
};

int main(){
    setDefault();

    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, cmp> pq;
    for(int i=0; i<n; ++i){
        int command;
        cin >> command;

        if(command != 0){
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
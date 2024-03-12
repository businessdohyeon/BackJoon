/*
BaekJoon No
#24511
*/

#include <iostream>
#include <vector>
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

    vector<int> isStackArr;
    for(int i=0; i<n; ++i){
        int isStack;
        cin >> isStack;
        isStackArr.push_back(isStack);
    }

    deque<int> dq;
    
    for(int i=0; i<n; ++i){
        int firstElement;
        cin >> firstElement;
        if(!isStackArr[i])
            dq.push_back(firstElement);
    }

    int m;
    cin >> m;
    for(int i=0; i<m; ++i){
        int input;
        cin >> input;

        dq.push_front(input);
        cout << dq.back() << ' ';
        dq.pop_back();
    }    

    return 0;
}
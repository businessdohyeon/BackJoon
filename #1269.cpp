/*
BaekJoon No
#1269
*/

#include <iostream>
#include <set>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    int n, m;
    cin >> n >> m;

    set<int> a;
    for(int i=0; i<n; ++i){
        int input;
        cin >> input;
        a.insert(input);
    }
    set<int> b;
    for(int i=0; i<m; ++i){
        int input;
        cin >> input;
        b.insert(input);
    }

    int cnt = 0;
    for(int num : a)
        if(b.find(num) == b.end())    ++cnt;
    for(int num : b)
        if(a.find(num) == a.end())    ++cnt;

    cout << cnt;

    return 0;
}
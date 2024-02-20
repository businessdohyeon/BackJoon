/*
BaekJoon No
#10816
*/

#include <iostream>
#include <unordered_map>

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

    unordered_map<int, int> cnt;
    for(int i=0; i<n; ++i){
        int input;
        cin >> input;
        if(cnt.find(input)!=cnt.end())  ++cnt[input];
        else                            cnt[input] = 1;
    }

    int m;
    cin >> m;

    for(int i=0; i<m; ++i){
        int input;
        cin >> input;
        if(cnt.find(input)!=cnt.end())
            cout << cnt[input] << ' ';
        else
            cout << 0 << ' ';
    }

    return 0;
}
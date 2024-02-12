/*
BaekJoon No
#11651
*/

#include <iostream>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)    return a.first < b.first;
    else                        return a.second < b.second;
}

int main(){
    setDefault();

    int n;
    cin >> n;

    pair<int, int> s[n];

    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        s[i] = make_pair(x, y);
    }
    
    sort(s, s+n, comp);

    for(int i=0; i<n; ++i)
        cout << s[i].first << ' ' << s[i].second << '\n';

    return 0;
}
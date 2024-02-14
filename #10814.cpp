/*
BaekJoon No
#10814
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

bool comp(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(){
    setDefault();

    int n;
    cin >> n;

    pair<int, string> s[n];
    for(int i=0; i<n; ++i){
        int age;    string name;
        cin >> age >> name;
        s[i] = make_pair(age, name);
    }

    stable_sort(s, s+n, comp);

    for(int i=0; i<n; ++i)
        cout << s[i].first << ' ' << s[i].second << '\n';

    return 0;
}
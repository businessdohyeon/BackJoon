/*
BaekJoon No
#18870
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    int s[n];
    for(int i=0; i<n; ++i)
        cin >> s[i];

    vector<int> v(s, s+n);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i=0; i<n; i++)
        cout << lower_bound(v.begin(), v.end(), s[i]) - v.begin() << ' ';

    return 0;
}
/*
BaekJoon No
#12015
*/

#include <iostream>
#include <vector>
#include <algorithm>

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

    int s[n];
    for(int i=0; i<n; ++i)
        cin >> s[i];
    
    vector<int> v;
    v.push_back(s[0]);
    for(int i=1; i<n; ++i)
        if(s[i] > v.back())
            v.push_back(s[i]);
        else
            *lower_bound(v.begin(), v.end(), s[i]) = s[i];
    
    cout << v.size();

    return 0;
}
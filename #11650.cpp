/*
BaekJoon No
#11650
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

bool comp(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }else{
        return a[0] < b[0];
    }
}

int main(){
    setDefault();

    int n;
    cin >> n;

    vector<int> v[n];
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;

        v[i].push_back(x);
        v[i].push_back(y);
    }

    sort(v, v+n, comp);

    for(int i=0; i<n; ++i)
        cout << v[i][0] << " " << v[i][1] << '\n';
    
    return 0;
}
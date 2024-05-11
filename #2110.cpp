/*
BaekJoon No
#2110
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

    int n, m;
    cin >> n >> m;
    
    vector<int> pos(n);
    for(int i=0; i<n; ++i)
        cin >> pos[i];
    
    sort(pos.begin(), pos.end());

    int ans = 0;
    int start = 0;
    int end = pos[n-1] - pos[0];
    while(start<=end){
        int mid = (start+end)/2;

        int cnt = 1;
        int before = pos[0];
        for(int i=1; i<n; ++i){
            if(pos[i]-before >= mid){
                ++cnt;
                before = pos[i];
            }
        }

        if(cnt >= m){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }

    cout << ans;

    return 0;
}
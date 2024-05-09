/*
BaekJoon No
#2805
*/

#include <iostream>

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

    int max = 0;
    int tree[n];
    for(int i=0; i<n; ++i){
        cin >> tree[i];
        if(tree[i] > max)
            max = tree[i];
    }

    int ans = 0;
    int start = 0;
    int end = max;
    while(start<end){
        int mid = (start+end)/2;

        long long cal = 0;
        for(int i=0; i<n; ++i){
            long long cutted = tree[i] - mid;
            cal += cutted > 0 ? cutted : 0;
        }
        
        if(cal >= m){
            start = mid+1;
            ans = mid;
        }else{
            end = mid;
        }
    }

    cout << ans;

    return 0;
}
/*
BaekJoon No
#1300
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

    long long n, k;
    cin >> n >> k;

    long long ans;
    long long start = 0;
    long long end = k;
    while(start<=end){
        long long mid = (start+end)/2;

        long long cal = 0;
        for(long long i = 1; i <= n; ++i)
            cal += (mid/i > n ? n : mid/i);

        if(cal >= k){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    cout << ans;

    return 0;
}
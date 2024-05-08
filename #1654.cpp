/*
BaekJoon No
#1654
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

    int has, need;
    cin >> has >> need;

    int wire[has];
    int max;
    for(int i=0; i<has; ++i){
        cin >> wire[i];
        if(i==0 || wire[i] > max)
            max = wire[i];
    }

    long long ans = 0;
    long long start = 0;
    long long end = max;

    long long cal = 0;
    for(int i=0; i<has; ++i)
        cal += wire[i] / end;

    if(cal >= need)
        ans = end;

    while(true){
        long long mid = (start+end)/2;

        if(start == mid || end == mid)  break;

        cal = 0;
        for(int i=0; i<has; ++i)
            cal += wire[i] / mid;

        if(cal < need){
            end = mid;
        }else{
            if(mid > ans)
                ans = mid;
            start = mid;
        }
    }
    
    cout << ans;

    return 0;
}
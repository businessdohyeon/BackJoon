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

    long long has, need;
    cin >> has >> need;

    long long wire[has];
    long long max;
    for(long long i=0; i<has; ++i){
        cin >> wire[i];
        if(i==0){
            max = wire[i];
        }else{
            if(wire[i] > max)
                max = wire[i];
        }
    }

    // has <= need
    // has가 1인 경우
    // need가 1인 경우

    if(has == 1){
        cout << wire[0]/need;
        return 0;
    }

    if(need == 1){
        cout << max;
        return 0;
    }


    long long start = 0;
    long long end = max;
    long long mid = (start+end)/2;
    long long ans = 0;

    long long cal = 0;
    for(long long i=0; i<has; ++i){
        cal += wire[i] / end;
    }
    if(cal >= need && mid > ans){
        ans = end;
    }

    // cout << ans << "!!" << endl;/


    while(mid>0){
        mid = (start+end)/2;

        if(start == mid || end == mid){
            break;
        }

        // cout << "start = " << start << " end = " << end << " | mid = " << mid << endl;

        long long cal = 0;
        for(long long i=0; i<has; ++i){
            cal += wire[i] / mid;
        }

        // cout << cal << endl;

        if(cal >= need && mid > ans){
            ans = mid;
        }

        if(cal < need){     // 좌측
            end = mid;
        }else if(cal >= need){   // 우측
            start = mid;
        }

        
    }
    
    cout << ans;

    return 0;
}
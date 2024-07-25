/*
BackJoon No.
#1019
*/

#include <iostream>
#include <algorithm>

using namespace std;

void bruteCnt(int ans[], int n, int weight){
    while(n>0){
        ans[n%10] += weight;
        n /= 10;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int pageNum;
    cin >> pageNum;

    int ans[10];
    fill(ans, ans+10, 0);

    int weight = 1;
    while(true){
        if(pageNum/10 == 0){
            while(pageNum>0){
                bruteCnt(ans, pageNum, weight);
                --pageNum;
            }
            break;
        }

        while(pageNum%10 != 9){
            bruteCnt(ans, pageNum, weight);
            --pageNum;
        }

        int factor = (pageNum/10 +1) * weight;
        for(int i=0; i<10; ++i)
            ans[i] += factor;
        
        ans[0] -= weight;

        pageNum/=10;
        weight *= 10;
    }

    for(int i=0; i<10; ++i)
        cout << ans[i] << ' ';

    return 0;
}
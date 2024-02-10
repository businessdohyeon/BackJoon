/*
BaekJoon No
#1427
*/

#include <iostream>
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

    int s[10] = {0};
    int cnt = 0;
    while(n>0){
        s[cnt] = n %10;
        n /= 10;
        ++cnt;
    }

    sort(s, s+cnt, greater<int>());

    for(int i=0; i <cnt; ++i)
        cout << s[i];
    
    return 0;
}
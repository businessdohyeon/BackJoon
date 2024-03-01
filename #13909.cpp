/*
BaekJoon No
#13909
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

    int n;
    cin >> n;

    int cnt = 0;
    for(int i=1; i*i<=n; ++i)
        ++cnt;
    cout << cnt;

    
    return 0;
}
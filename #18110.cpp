/*
BackJoon No.
#18110
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if(n == 0){
        cout << 0;
        return 0;
    }

    int s[n];
    for(int i=0; i<n; ++i)
        cin >> s[i];

    int cutNum = double(n) * 0.15 + 0.5;
    
    sort(s, s+n);

    int sum = 0;
    for(int i=cutNum; i<n-cutNum; ++i)
        sum += s[i];

    int av = double(sum) / (n - 2*cutNum) + 0.5;
    cout << av;

    return 0;
}
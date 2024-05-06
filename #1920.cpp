/*
BaekJoon No
#1920
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

    int n;
    cin >> n;

    vector<int> input(n);
    for(int i=0; i<n; ++i)
        cin >> input[i];

    sort(input.begin(), input.end());

    int m;
    cin >> m;
    
    for(int i=0; i<m; ++i){
        int findthis;
        cin >> findthis;
        cout << binary_search(input.begin(), input.end(), findthis) << '\n';
    }

    return 0;
}
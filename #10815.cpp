/*
BaekJoon No
#10815
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
    int has[n];
    for(int i=0; i<n; ++i)
        cin >> has[i];

    int m;
    cin >> m;
    int find[m];
    for(int i=0; i<m; ++i)
        cin >> find[i];


    sort(has, has+n);

    for(int i=0; i<m; ++i)
        cout << int(binary_search(has, has+n, find[i])) << ' ';


    return 0;
}
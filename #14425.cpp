/*
BaekJoon No
#14425
*/

#include <iostream>
#include <string>
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
    string input[n];
    for(int i=0; i<n; ++i)
        cin >> input[i];

    int m;
    cin >> m;
    string find[m];
    for(int i=0; i<m; ++i)
        cin >> find[i];


    sort(input, input+n);

    for(int i=0; i<n; ++i)
        cout << input[i] << endl;

    short cnt = 0;
    for(int i=0; i<m; ++i)
        if(binary_search(input, input+n, find[i]))
            ++cnt;

    cout << cnt;

    return 0;
}
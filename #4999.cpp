/*
BackJoon No.
#4999
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << (a.length() >= b.length() ? "go" : "no");

    return 0;
}
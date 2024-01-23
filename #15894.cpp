/*
BaekJoon No
#15894
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    unsigned int n;
    cin >> n;
    cout << 4*n;

    return 0;
}
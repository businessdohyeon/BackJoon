/*
BaekJoon No
#2292
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    int result;
    
    --n;

    int i;
    for(i=1; n>0; ++i)  n -= 6*i;

    result = i;

    cout << result;
    
    return 0;
}
/*
BaekJoon No
#2485
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int gcd(int a, int b){
    int remainder = a % b;
    if(remainder == 0)  return b;
    else                return gcd(b, remainder);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    int treeDistance[n];
    for(int i=0; i<n; ++i)
        cin >> treeDistance[i];

    int gap[n-1];
    for(int i=0; i<n-1; ++i)
        gap[i] = treeDistance[i+1] - treeDistance[i];

    int gcdGap = gcd(gap[0], gap[1]);
    for(int i=2; i<n-1; ++i)
        gcdGap = gcd(gcdGap, gap[i]);

    int result = 0;
    for(int i=0; i<n-1; ++i)
        result += gap[i] / gcdGap -1;
    
    cout << result;

    return 0;
}
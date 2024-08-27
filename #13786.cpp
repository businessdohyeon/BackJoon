/*
BackJoon No.
#13786
*/

#include <iostream>

using namespace std;

typedef pair<long long int, long long int> Pos;

bool isCCW(Pos a, Pos b, Pos c){
    long long int cal = (a.first*b.second + b.first*c.second + c.first*a.second) - 
        (b.first*a.second + c.first*b.second + a.first*c.second);
    return (cal > 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Pos a1, a2, b1, b2;
    cin >> a1.first >> a1.second;
    cin >> a2.first >> a2.second;
    cin >> b1.first >> b1.second;
    cin >> b2.first >> b2.second;

    int ans = (isCCW(a1, a2, b1) != isCCW(a1, a2, b2)) && (isCCW(b1, b2, a1) != isCCW(b1, b2, a2));
    cout << ans;

    return 0;
}
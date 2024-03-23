/*
BaekJoon No
#11729
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void hanoi(int size, int from, int to, int spare){
    if(size == 1){
        cout << from << ' ' << to << '\n';
        return;
    }

    hanoi(size-1, from, spare, to);
    hanoi(1, from, to, spare);
    hanoi(size-1, spare, to, from);
    return;
}

int main(){
    setDefault();

    int n;
    cin >> n;

    // cnt = 2^n - 1
    int cnt = 1;
    for(int i=0; i<n; ++i)
        cnt *= 2;
    cnt -= 1;

    cout << cnt << '\n';
    hanoi(n, 1, 3, 2);

    return 0;
}
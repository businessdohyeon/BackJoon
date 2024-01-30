/*
BaekJoon No
#1085
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int x, y ,w ,h;
    cin >> x >> y >> w >> h;

    int min_x = x < w-x ? x : w-x;
    int min_y = y < h-y ? y : h-y;
    int min_distance = min_x < min_y ? min_x : min_y;
    cout << min_distance;

    return 0;
}
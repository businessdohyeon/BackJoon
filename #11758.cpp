/*
BackJoon No.
#11758
*/

#include <iostream>
#include <cmath>

using namespace std;

typedef pair<int, int> Pos;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Pos points[3];
    for(int i=0; i<3; ++i)
        cin >> points[i].first >> points[i].second;

    int ccw = (points[0].first*points[1].second 
                    + points[1].first*points[2].second 
                    + points[2].first*points[0].second)
                - 
                (points[1].first*points[0].second 
                    + points[2].first*points[1].second 
                    + points[0].first*points[2].second);

    int result = int(ccw > 0) - int(ccw <  0);

    cout << result;

    return 0;
}
/*
BackJoon No.
#2618
*/

#include <iostream>
#include <cmath>

using namespace std;

struct Pos{
    int x, y;
};

int n, w;
Pos event[1001];
int dp_cost[1001][1001];
int dp_policeCar[1001][1001];

int getDistance(Pos from, Pos to){
    int dx = abs(from.x - to.x);
    int dy = abs(from.y - to.y);
    return dx+dy;
}
int getMinCost(int p1, int p2){
    if(p1 >= w || p2 >= w)      return 0;
    if(dp_cost[p1][p2] != 0)    return dp_cost[p1][p2];

    int idx_of_nextEvent = max(p1, p2) + 1;
    Pos nextEvent = event[idx_of_nextEvent];

    int d1 = (p1 == 0 ? getDistance({1, 1}, nextEvent) : getDistance(event[p1], nextEvent));
    int d2 = (p2 == 0 ? getDistance({n, n}, nextEvent) : getDistance(event[p2], nextEvent));
    int case1 = getMinCost(idx_of_nextEvent, p2) + d1;
    int case2 = getMinCost(p1, idx_of_nextEvent) + d2;

    if(case1 < case2){
        dp_cost[p1][p2] = case1;
        dp_policeCar[p1][p2] = 1;
    }else{
        dp_cost[p1][p2] = case2;
        dp_policeCar[p1][p2] = 2;
    }

    return dp_cost[p1][p2];
}
void printMinPath(int p1, int p2){
    if(p1 >= w || p2 >= w)  return;

    cout << dp_policeCar[p1][p2] << '\n';
    
    int idx_of_nextEvent = max(p1, p2) + 1;
    if(dp_policeCar[p1][p2] == 1)
        printMinPath(idx_of_nextEvent, p2);
    else
        printMinPath(p1, idx_of_nextEvent);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> w;
    
    for(int i=1; i<=w; ++i)
        cin >> event[i].x >> event[i].y;

    cout << getMinCost(0, 0) << '\n';
    printMinPath(0, 0);

    return 0;
}
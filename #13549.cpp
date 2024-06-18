/*
BackJoon No
#13549
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int COEFFICIENT[] = {1, 1, 2};
    const int BIAS[] = {-1, 1, 0};
    const int COST[] = {1, 1, 0};

    int n, k;
    cin >> n >> k;

    // {cost, node}
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0, n));

    int minCost[100000];
    fill(minCost, minCost+100000, -1);
    minCost[n] = 0;

    while(!pq.empty()){
        pair<int,int> front = pq.top();
        int curCost = front.first;
        int curNode = front.second;
        pq.pop();

        if(curNode == k)    break;

        for(int i=0; i<3; ++i){
            int cal = curCost + COST[i];
            int nextNode = COEFFICIENT[i]*curNode + BIAS[i];

            if(nextNode<0 || nextNode>100000)   continue;

            if(minCost[nextNode] == -1 || cal < minCost[nextNode]){
                minCost[nextNode] = cal;
                pq.push(make_pair(cal, nextNode));
            }
        }
    }

    cout << minCost[k];

    return 0;
}
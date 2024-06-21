/*
BackJoon No.
#11404
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
// { to , weight }
vector<pair<int,int> > graph[101];

int dijkstra(int from, int to){
    // { -cost, node }
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, from));

    int minCost[n+1];
    fill(minCost, minCost+n+1, -1);
    minCost[from] = 0;

    while(!pq.empty()){
        pair<int, int> front = pq.top();
        int curCost = -front.first;
        int curNode = front.second;
        pq.pop();

        if(curNode == to)   break;

        for(auto e : graph[curNode]){
            int cal = curCost + e.second;
            int nextNode = e.first;

            if(minCost[nextNode] != -1 && cal >= minCost[nextNode]) continue;

            minCost[nextNode] = cal;
            pq.push(make_pair(-cal, nextNode));
        }
    }

    int result = minCost[to] == -1 ? 0 : minCost[to];
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    
    for(int i=0; i<m; ++i){
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        graph[v1].push_back(make_pair(v2, weight));
    }

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j)
            cout << dijkstra(i, j) << ' ';
        cout << '\n';
    }

    return 0;
}
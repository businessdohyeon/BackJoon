/*
BackJoon No.
#1504
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge{
    int to, weight;
};

int n, e;
vector<Edge> graph[801];

int shortestPath(int from, int to){
    // { cost, node }
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0, from));

    int minCost[n+1];
    fill(minCost, minCost+n+1, -1);
    minCost[from] = 0;

    while(!pq.empty()){
        pair<int,int> front = pq.top();
        int curCost = front.first;
        int curNode = front.second;
        pq.pop();

        for(Edge e : graph[curNode]){
            int cal = curCost + e.weight;
            int nextNode = e.to;
            if(minCost[nextNode] == -1 || cal < minCost[nextNode]){
                minCost[nextNode] = cal;
                pq.push(make_pair(cal, nextNode));
            }
        }
    }

    return minCost[to];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> e;
    
    for(int i=0; i<e; ++i){
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        Edge e1 = {v2, weight};
        Edge e2 = {v1, weight};
        graph[v1].push_back(e1);
        graph[v2].push_back(e2);
    }

    int stopOver1, stopOver2;
    cin >> stopOver1 >> stopOver2;

    int partial1, partial2, partial3;
    int path1, path2;

    partial1 = shortestPath(1, stopOver1);
    partial2 = shortestPath(stopOver1, stopOver2);
    partial3 = shortestPath(stopOver2, n);
    if(partial1 == -1 || partial2 == -1 || partial3 == -1)
        path1 = -1;
    else
        path1 = partial1 + partial2 + partial3;

    partial1 = shortestPath(1, stopOver2);
    partial2 = shortestPath(stopOver2, stopOver1);
    partial3 = shortestPath(stopOver1, n);
    if(partial1 == -1 || partial2 == -1 || partial3 == -1)
        path2 = -1;
    else
        path2 = partial1 + partial2 + partial3;

    if(path1 == -1 && path2 == -1)
        cout << -1;
    else if(path1 == -1)
        cout << path2;
    else if(path2 == -1)
        cout << path1;
    else
        cout << min(path1, path2);

    return 0;
}
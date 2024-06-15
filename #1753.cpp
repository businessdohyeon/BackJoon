/*
BackJoon No.
#1753
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, start;
    cin >> v >> e >> start;

    vector<pair<int, int> > graph[v+1];
    for(int i=0; i<e; ++i){
        int from, to, w;
        cin >> from >> to >> w;
        graph[from].push_back(make_pair(to, w));
    }
    
    int cost[v+1];
    fill(cost, cost+v+1, -1);
    cost[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        auto front = pq.top();
        int curNode = front.second;
        int curCost = front.first;
        pq.pop();

        for(auto e : graph[curNode]){
            int nextNode = e.first;
            int cal = curCost + e.second;

            if(cost[nextNode] != -1 && cost[nextNode] < cal)  continue;

            cost[nextNode] = cal;
            pq.push(make_pair(cal, nextNode));
        }
    }

    for(int node=1; node<=v; ++node)
        if(cost[node] == -1)
            cout << "INF" << '\n';
        else
            cout << cost[node] << '\n';

    return 0;
}
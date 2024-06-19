/*
BackJoon No
#9370
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge{
    int to, weight;
};

int num_v, num_edge, num_dest;
int start, g, h;
vector<Edge> graph[50001];
int dest[100];

int dijkstra(int from, int to){
    // {cost, node}
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0, from));

    int minCost[num_v+1];
    fill(minCost, minCost+num_v+1, -1);
    minCost[from] = 0;

    while(!pq.empty()){
        pair<int, int> front = pq.top();
        int curCost = -front.first;
        int curNode = front.second;
        pq.pop();

        if(curNode == to)   break;

        for(auto e : graph[curNode]){
            int cal = curCost + e.weight;
            int nextNode = e.to;
            if(minCost[nextNode] == -1 || cal < minCost[nextNode]){
                minCost[nextNode] = cal;
                pq.push(make_pair(-cal, nextNode));
            }
        }
    }

    return minCost[to];
}

int sequencialDijkstra(vector<int> nodes){
    int sum = 0;
    for(int i=0; i<nodes.size()-1; ++i){
        int cost = dijkstra(nodes[i], nodes[i+1]);
        if(cost == -1)  return -1;
        sum += cost;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num_test;
    cin >> num_test;

    for(int t=0; t<num_test; ++t){
        cin >> num_v >> num_edge >> num_dest;
        cin >> start >> g >> h;

        for(int i=0; i<num_edge; ++i){
            int v1, v2, weight;
            cin >> v1 >> v2 >> weight;
            Edge e1 = {v2, weight};
            Edge e2 = {v1, weight};
            graph[v1].push_back(e1);
            graph[v2].push_back(e2);
        }

        vector<int> ans;
        for(int i=0; i<num_dest; ++i){
            int dest;
            cin >> dest;

            vector<int> case1 = {start, g, h, dest};
            vector<int> case2 = {start, h, g, dest};
            vector<int> caseMinCost = {start, dest};
            int cost1 = sequencialDijkstra(case1);
            int cost2 = sequencialDijkstra(case2);
            int minCost = sequencialDijkstra(caseMinCost);

            if(cost1 == -1 && cost2 == -1)  continue;
            
            int cal;
            if(cost1 == -1)         cal = cost2;
            else if(cost2 == -1)    cal = cost1;
            else                    cal = min(cost1, cost2);

            if(cal != minCost)  continue;

            ans.push_back(dest);
        }

        sort(ans.begin(), ans.end());

        for(int e : ans)
            cout << e << ' ';
        cout << '\n';

        for(int i=1; i<=num_v; ++i)
            graph[i].clear();
    }

    return 0;
}
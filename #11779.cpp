/*
BackJoon No.
#11779
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int RANGE_MAX = 1000;

    int n, m;
    cin >> n >> m;

    // { to, weight }
    vector<pair<int, int> > graph[n+1];
    for(int _=0; _<m; ++_){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1].push_back(make_pair(v2, w));
    }

    int from, to;
    cin >> from >> to;

    int minCost[RANGE_MAX+1];
    fill(minCost, minCost+RANGE_MAX+1, -1);
    minCost[from] = 0;

    int prevVisited[RANGE_MAX+1];
    fill(prevVisited, prevVisited+RANGE_MAX+1, -1);
    prevVisited[from] = -2;

    // { -cost, node }
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, from));
    while(!pq.empty()){
        auto front = pq.top();
        int curCost = -front.first;
        int curNode = front.second;
        pq.pop();

        if(curNode == to)   break;

        for(auto e : graph[curNode]){
            int nextCost = curCost + e.second;
            int nextNode = e.first;

            if(minCost[nextNode] == -1 || nextCost < minCost[nextNode]){
                minCost[nextNode] = nextCost;
                prevVisited[nextNode] = curNode;
                pq.push(make_pair(-nextCost, nextNode));
            }
        }
    }

    deque<int> path;
    for(int i=to; i != from; i = prevVisited[i])
        path.push_front(i);
    path.push_front(from);

    cout << minCost[to] << '\n';

    cout << path.size() << '\n';
    for(int e : path)
        cout << e << ' ';

    return 0;
}
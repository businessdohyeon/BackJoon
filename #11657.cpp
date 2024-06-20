/*
BackJoon No.
#11657
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    long long int from, to, weight;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> graph;
    for(int i=0; i<m; ++i){
        Edge newEdge;
        cin >> newEdge.from >> newEdge.to >> newEdge.weight;
        graph.push_back(newEdge);
    }

    bool isFirst[n+1];
    fill(isFirst, isFirst+n+1, true);
    isFirst[1] = false;

    long long int minCost[n+1];
    minCost[1] = 0;

    for(int i=0; i<n-1; ++i){
        for(Edge e : graph){
            if(isFirst[e.from])     continue;

            long long int cal = minCost[e.from] + e.weight;
            if(!isFirst[e.to] && cal >= minCost[e.to])  continue;

            isFirst[e.to] = false;
            minCost[e.to] = cal;
        }
    }

    for(Edge e : graph){
        if(isFirst[e.from])     continue;

        long long int cal = minCost[e.from] + e.weight;
        if(!isFirst[e.to] && cal >= minCost[e.to])  continue;

        cout << -1;
        return 0;
    }

    for(int i=2; i<=n; ++i)
        if(isFirst[i])  cout << -1 << '\n';
        else            cout << minCost[i] << '\n';
    
    return 0;
}
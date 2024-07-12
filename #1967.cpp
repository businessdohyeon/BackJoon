/*
BackJoon No.
#1967
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int RANGE_MAX = 10000;

int n;
vector<pair<int,int> > graph[RANGE_MAX+1];
bool isVisited[RANGE_MAX+1];
int maxCost, maxCostNode;

void dfs(int parent, int costSum){
    isVisited[parent] = true;
    if(costSum > maxCost){
        maxCost = costSum;
        maxCostNode = parent;
    }
    for(auto e : graph[parent])
        if(!isVisited[e.first])
            dfs(e.first, costSum+e.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int _=0; _<n-1; ++_){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1].push_back(make_pair(v2, w));
        graph[v2].push_back(make_pair(v1, w));
    }

    dfs(1, 0);

    fill(isVisited, isVisited+RANGE_MAX+1, false);
    dfs(maxCostNode, 0);

    cout << maxCost;

    return 0;
}
/*
BackJoon No.
#1167
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int RANGE_MAX = 100000;

int n;
// { to, weight }
vector<pair<int,int> > graph[RANGE_MAX+1];
int maxCost, maxCostNode;
bool isVisited[RANGE_MAX+1];
void dfs(int parent, int sumCost){
    isVisited[parent] = true;
    if(maxCost < sumCost){
        maxCost = sumCost;
        maxCostNode = parent;
    }
    for(auto e : graph[parent])
        if(!isVisited[e.first])
            dfs(e.first, sumCost+e.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    for(int _=0; _<n; ++_){
        int v1, v2, w;
        cin >> v1;
        while(true){
            cin >> v2;
            if(v2 == -1)    break;
            cin >> w;
            graph[v1].push_back(make_pair(v2, w));
        }
    }

    dfs(1, 0);

    fill(isVisited, isVisited+RANGE_MAX+1, false);
    
    dfs(maxCostNode, 0);

    cout << maxCost;

    return 0;
}
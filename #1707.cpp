/*
BackJoon No.
#1707
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, int flag, int isVisited[], vector<int> graph[]){
    if(isVisited[start] != 0)
        return;

    isVisited[start] = flag;

    for(auto e : graph[start])
        if(isVisited[e] == 0)
            dfs(e, -1*flag, isVisited, graph);
}

bool isBiparitie(int v, int isVisited[], vector<int> graph[]){
    for(int node=1; node<=v; ++node)
        for(int e : graph[node])
            if(isVisited[e] == isVisited[node])
                return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    
    for(int i = 0; i < k; ++i){
        int v, e;
        cin >> v >> e;

        vector<int> graph[v+1];
        for(int j=0; j<e; ++j){
            int v1, v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        int isVisited[v+1];
        fill(isVisited, isVisited+v+1, 0);

        for(int node=1; node<=v; ++node)
            dfs(node, 1, isVisited, graph);

        if(isBiparitie(v, isVisited, graph))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}
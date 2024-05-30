/*
BackJoon No.
#24479
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> > &graph, int* visited, int& cnt, int start){
    visited[start] = cnt;
    ++cnt;

    for(auto e : graph[start])
        if(visited[e] == 0)
            dfs(graph, visited, cnt, e);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; ++i){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i=1; i<=n; ++i)
        sort(graph[i].begin(), graph[i].end());

    int visited[n+1];
    fill(visited, visited+n+1, 0);
    int cnt = 1;
    dfs(graph, visited, cnt, r);

    for(int i=1; i<=n; ++i)
        cout << visited[i] << '\n';

    return 0;
}
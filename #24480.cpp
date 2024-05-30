/*
BackJoon No.
#24480
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
vector<vector<int> > graph(100001);
int visited[100001];
int cnt = 1;

void dfs(int node){
    visited[node] = cnt;
    ++cnt;

    for(auto e : graph[node])
        if(!visited[e])
            dfs(e);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;

    for(int i=0; i<m; ++i){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i=1; i<=n; ++i)
        sort(graph[i].begin(), graph[i].end(), greater<int>());

    dfs(r);

    for(int i=1; i<=n; ++i)
        cout << visited[i] << '\n';

    return 0;
}
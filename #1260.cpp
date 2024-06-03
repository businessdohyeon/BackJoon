/*
BackJoon No.
#1260
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, v;
vector<vector<int> > edges(1001);
bool visited[1001];

void dfs(int start){
    cout << start << ' ';
    visited[start] = true;

    for(auto e : edges[start])
        if(visited[e] == 0)
            dfs(e);
}

void bfs(int start){
    queue<int> q;
    
    cout << start << ' ';
    visited[start] = true;

    q.push(start);
    while (!q.empty()){
        int front = q.front();
        q.pop();
        for(auto e : edges[front]){
            if(visited[e] == 0){
                cout << e << ' ';
                visited[e] = true;
                q.push(e);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> v;

    for(int i=0; i<m; ++i){
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }

    for(int i=1; i<=n; ++i)
        sort(edges[i].begin(), edges[i].end());

    dfs(v);
    cout << '\n';

    fill(visited+1, visited+n+1, false);

    bfs(v);

    return 0;
}
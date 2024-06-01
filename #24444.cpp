/*
BackJoon No.
#24444
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m , r;
int visited[100001];
vector<vector<int> > edges(100001);
int cnt = 1;

void bfs(int start){
    visited[start] = cnt;
    ++cnt;

    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(auto e : edges[tmp]){
            if(visited[e] == 0){
                visited[e] = cnt;
                ++cnt;
                q.push(e);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;

    for(int i=0; i<m; ++i){
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }

    for(int i=1; i<=n; ++i)
        sort(edges[i].begin(), edges[i].end());

    bfs(r);

    for(int i=1; i<=n; ++i)
        cout << visited[i] << '\n';

    return 0;
}
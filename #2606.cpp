/*
BackJoon No.
#2606
*/

#include <iostream>
#include <vector>

using namespace std;

int num, cnt;
vector<vector<int> > edges(101);
bool visited[101];

void dfs(int start){
    visited[start] = true;
    for(auto e : edges[start])
        if(!visited[e])
            dfs(e);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> num >> cnt;

    for(int i=0; i<cnt; ++i){
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }

    dfs(1);

    int ans = 0;
    for(int i=2; i<=num; ++i)
        if(visited[i])
            ++ans;

    cout << ans;

    return 0;
}
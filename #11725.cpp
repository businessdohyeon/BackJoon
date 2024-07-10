/*
BackJoon No.
#11725
*/

#include <iostream>
#include <vector>

using namespace std;

const int RANGE_MAX = 100000;

int n;
vector<int> graph[RANGE_MAX+1];
int parentNode[RANGE_MAX+1];
bool isVisited[RANGE_MAX+1];

void dfs(int parent){
    isVisited[parent] = true;
    
    for(auto e : graph[parent]){
        if(!isVisited[e]){
            parentNode[e] = parent;
            dfs(e);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    for(int _=0; _<n-1; ++_){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(1);

    for(int i=2; i<=n; ++i)
        cout << parentNode[i] << '\n';

    return 0;
}
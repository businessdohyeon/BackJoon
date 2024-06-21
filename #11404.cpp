/*
BackJoon No.
#11404
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // { to , weight }
    vector<pair<int,int> > graph[n+1];    
    for(int i=0; i<m; ++i){
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        graph[v1].push_back(make_pair(v2, weight));
    }

    int result[n+1][n+1];
    for(int row=1; row<=n; ++row)
        fill(result[row], result[row]+n+1, -1);

    for(int node=1; node<=n; ++node){
        result[node][node] = 0;
        for(auto e : graph[node]){
            if(result[node][e.first] != -1 && e.second >= result[node][e.first])    continue;
            result[node][e.first] = e.second;
        }
    }
    
    for(int mid=1; mid<=n; ++mid){
        for(int from=1; from<=n; ++from){
            for(int to=1; to<=n; ++to){
                if(result[from][mid] == -1 || result[mid][to] == -1)    continue;

                int cal = result[from][mid]+result[mid][to];
                if(result[from][to] == -1 || cal < result[from][to])
                    result[from][to] = cal;
            }
        }
    }

    for(int from=1; from<=n; ++from){
        for(int to=1; to<=n; ++to)
            if(result[from][to] == -1)  cout << 0 << ' ';
            else                        cout << result[from][to] << ' ';
        cout << '\n';
    }

    return 0;
}
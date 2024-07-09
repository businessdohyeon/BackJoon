/*
BackJoon No.
#11780
*/

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long minCost[n+1][n+1];
    memset(minCost, 0, sizeof(minCost));
    vector<int> prevVisited[n+1][n+1];
    for(int _=0; _<m; ++_){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        if(minCost[v1][v2] == 0 || w < minCost[v1][v2]){
            minCost[v1][v2] = w;
            prevVisited[v1][v2] = {v1, v2};
        }
    }

    for(int mid=1; mid<=n; ++mid){
        for(int from=1; from<=n; ++from){
            for(int to=1; to<=n; ++to){
                if(from == to || minCost[from][mid] == 0 || minCost[mid][to] == 0)
                    continue;

                int cal = minCost[from][mid] + minCost[mid][to];
                if(minCost[from][to] == 0 || cal < minCost[from][to]){
                    minCost[from][to] = cal;

                    prevVisited[from][to] = prevVisited[from][mid];
                    for(int idx=1; idx<prevVisited[mid][to].size(); ++idx)
                        prevVisited[from][to].push_back(prevVisited[mid][to][idx]);
                }
            }
        }
    }

    for(int from=1; from<=n; ++from){
        for(int to=1; to<=n; ++to)
            cout << minCost[from][to] << ' ';
        cout << '\n';
    }

    for(int from=1; from<=n; ++from){
        for(int to=1; to<=n; ++to){
            cout << prevVisited[from][to].size();
            for(auto e : prevVisited[from][to])
                cout << ' ' << e;
            cout << '\n';
        }
    }

    return 0;
}
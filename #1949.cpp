/*
BackJoon No.
#1949
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int RANGE_MAX = 1e4;
const int RANDOM_ROOT = 1;

int nodeNum;
int weight[RANGE_MAX+1];
vector<int> edges[RANGE_MAX+1];
int dp[RANGE_MAX+1][2];
bool isVisited[RANGE_MAX+1];

void dfs(int root){
    isVisited[root] = true;

    dp[root][0] = weight[root];
    dp[root][1] = 0;
    for(auto e : edges[root]){
        if(isVisited[e])    continue;

        dfs(e);

        dp[root][0] += dp[e][1];
        dp[root][1] += max(dp[e][0], dp[e][1]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> nodeNum;
    
    for(int i=1; i<=nodeNum; ++i)
        cin >> weight[i];

    for(int _=0; _<nodeNum-1; ++_){
        int node1, node2;
        cin >> node1 >> node2;
        edges[node1].push_back(node2);
        edges[node2].push_back(node1);
    }

   dfs(RANDOM_ROOT);

   cout << max(dp[RANDOM_ROOT][0], dp[RANDOM_ROOT][1]);

    return 0;
}
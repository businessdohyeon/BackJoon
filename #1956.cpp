/*
BackJoon No
#1956
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    cin >> v >> e;

    vector<pair<int, int> > graph[v+1];
    for(int _=0; _<e; ++_){
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        graph[v1].push_back(make_pair(v2, weight));
    }

    int minCost[v+1][v+1];
    for(int row=0; row<v+1; ++row)
        fill(minCost[row], minCost[row]+v+1, -1);

    for(int node=1; node<=v; ++node){
        minCost[node][node] = 0;
        for(auto e : graph[node])
            minCost[node][e.first] = e.second;
    }

    for(int mid=1; mid<=v; ++mid){
        for(int from=1; from<=v; ++from){
            for(int to=1; to<=v; ++to){
                if(minCost[from][mid] == -1 || minCost[mid][to] == -1)  continue;
                
                int cal = minCost[from][mid] + minCost[mid][to];
                if(minCost[from][to] == -1 || cal < minCost[from][to])
                    minCost[from][to] = cal;
            }
        }
    }

    int minCycle = -1;
    for(int node=1; node<=v; ++node){
        for(int mid=1; mid<=v; ++mid){
            if(node == mid || minCost[node][mid] == -1 || minCost[mid][node] == -1)    continue;

            int cal = minCost[node][mid] + minCost[mid][node];
            if(minCycle == -1 || cal < minCycle)
                minCycle = cal;
        }
    }
    
    cout << minCycle;

    return 0;
}
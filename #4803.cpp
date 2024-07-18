/*
BackJoon No.
#4803
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isTree(vector<int> graph[], bool isVisited[], int target, int parent){
    isVisited[target] = true;

    for(auto e : graph[target]){
        if(e == parent)     continue;
        if(isVisited[e] || !isTree(graph, isVisited, e, target))
            return false;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int caseCnt=1; ; ++caseCnt){
        int nodeCnt, edgeCnt;
        cin >> nodeCnt >> edgeCnt;

        if(nodeCnt == 0 && edgeCnt == 0)    break;

        vector<int> graph[nodeCnt+1];
        for(int _=0; _<edgeCnt; ++_){
            int v1, v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        bool isVisited[nodeCnt+1];
        fill(isVisited, isVisited+nodeCnt+1, false);

        int treeCnt = 0;
        for(int node=1; node<=nodeCnt; ++node){
            if(isVisited[node])     continue;
            if(isTree(graph, isVisited, node, -1))
                ++treeCnt;
        }

        cout << "Case " << caseCnt << ": ";
        if(treeCnt == 0)        cout << "No trees.";
        else if(treeCnt == 1)   cout << "There is one tree.";
        else                    cout << "A forest of " << treeCnt << " trees.";
        cout << '\n';
    }

    return 0;
}
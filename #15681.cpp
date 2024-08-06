/*
BackJoon No.
#15681
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int RANGE_MAX = 100000;

int nodeNum, root, queryNum;
vector<int> edges[RANGE_MAX+1];
int isVisited[RANGE_MAX+1];
int subTreeNodeCnt[RANGE_MAX+1];

int cntSubTreeNode(int root){
    isVisited[root] = true;

    int result = 1;
    for(auto e : edges[root])
        if(!isVisited[e])
            result += cntSubTreeNode(e);

    subTreeNodeCnt[root] = result;
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> nodeNum >> root >> queryNum;

    for(int _=0; _<nodeNum-1; ++_){
        int node1, node2;
        cin >> node1 >> node2;
        edges[node1].push_back(node2);
        edges[node2].push_back(node1);
    }

    fill(isVisited, isVisited+nodeNum+1, false);
    fill(subTreeNodeCnt, subTreeNodeCnt+nodeNum+1, 0);

    cntSubTreeNode(root);

    for(int _=0; _<queryNum; ++_){
        int query;
        cin >> query;
        cout << subTreeNodeCnt[query] << '\n';
    }

    return 0;
}
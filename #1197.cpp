/*
BackJoon No.
#1197
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct Edge{
    int node1, node2, weight;
};

bool compare(Edge a, Edge b){
    if(a.weight != b.weight)    return a.weight < b.weight;
    if(a.node1 != b.node1)      return a.node1 < b.node1;
    return a.node2 < b.node2;
}
int findRoot(int unionFindArr[], int target){
    if(unionFindArr[target] == target)       return target;

    int root = findRoot(unionFindArr, unionFindArr[target]);
    unionFindArr[target] = root;
    return root;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum;

    Edge edges[edgeNum];
    for(int i=0; i<edgeNum; ++i)
        cin >> edges[i].node1 >> edges[i].node2 >> edges[i].weight;

    sort(edges, edges+edgeNum, compare);

    int unionFindArr[nodeNum+1];
    for(int i=1; i<=nodeNum; ++i)
        unionFindArr[i] = i;

    int ans = 0;
    for(int i=0; i<edgeNum; ++i){
        Edge& e = edges[i];
        int root_of_node1 = findRoot(unionFindArr, e.node1);
        int root_of_node2 = findRoot(unionFindArr, e.node2);

        if(root_of_node1 == root_of_node2)  continue;

        unionFindArr[max(root_of_node1, root_of_node2)] = min(root_of_node1, root_of_node2);
        ans += e.weight;
    }

    cout << ans;

    return 0;
}
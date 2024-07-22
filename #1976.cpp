/*
BackJoon No.
#1976
*/

#include <iostream>

using namespace std;

int findRoot(int rootOfNode[], int target){
    if(rootOfNode[target] == target)        return target;
    
    int root = findRoot(rootOfNode, rootOfNode[target]);
    rootOfNode[target] = root;
    return rootOfNode[target];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    int rootOfNode[n+1];
    for(int i=1; i<=n; ++i)
        rootOfNode[i] = i;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            bool isConencted;
            cin >> isConencted;

            if(!isConencted)    continue;

            int root_of_i = findRoot(rootOfNode, i);
            int root_of_j = findRoot(rootOfNode, j);
            if(root_of_i < root_of_j)
                rootOfNode[root_of_j] = root_of_i;
            else
                rootOfNode[root_of_i] = root_of_j;
        }
    }

    int plan[m];
    for(int i=0; i<m; ++i)
        cin >> plan[i];

    int commonRoot = rootOfNode[plan[0]];
    for(int i=1; i<m; ++i){
        if(rootOfNode[plan[i]] != commonRoot){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
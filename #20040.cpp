/*
BackJoon No.
#20040
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int findRoot(int rootArr[], const int target){
    if(rootArr[target] == target)      return target;
    
    const int root = findRoot(rootArr, rootArr[target]);
    rootArr[target] = root;
    return root;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nodeNum, turnNum;
    cin >> nodeNum >> turnNum;

    int rootArr[nodeNum];
    for(int i=0; i<nodeNum; ++i)
        rootArr[i] = i;

    int ans = 0;
    for(int turn=1; turn<=turnNum; ++turn){
        int v1, v2;
        cin >> v1 >> v2;

        const int root_of_v1 = findRoot(rootArr, v1);
        const int root_of_v2 = findRoot(rootArr, v2);

        if(root_of_v1 == root_of_v2){
            ans = turn;
            break;
        }
        
        rootArr[max(root_of_v1, root_of_v2)] = min(root_of_v1, root_of_v2);
    }

    cout << ans;

    return 0;
}
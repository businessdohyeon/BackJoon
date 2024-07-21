/*
BackJoon No.
#1717
*/

#include <iostream>
#include <vector>

using namespace std;

const int RANGE_MAX = 1000001;

int n, m;
int parent[RANGE_MAX];

int findRoot(int child){
    if(parent[child] == child)  return child;
    
    int root = findRoot(parent[child]);
    parent[child] = root;
    return root;
}
void merge(int a, int b){
    parent[findRoot(a)] = findRoot(b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<=n; ++i)
        parent[i] = i;

    for(int _=0; _<m; ++_){
        int command, a, b;
        cin >> command >> a >> b;

        if(command == 0){
            merge(a, b);
        }else{
            if(findRoot(a) == findRoot(b))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }

    return 0;
}
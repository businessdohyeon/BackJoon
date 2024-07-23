/*
BackJoon No.
#4195
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, string> rootMap;
unordered_map<string, int> memberCnt;

string findRoot(const string& target){
    if(rootMap[target] == target)       return target;

    const string root = findRoot(rootMap[target]);
    rootMap[target] = root;
    return root;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int numTest;
    cin >> numTest;

    for(int _=0; _<numTest; ++_){
        int numNetwork;
        cin >> numNetwork;

        rootMap.clear();
        memberCnt.clear();

        for(int __=0; __<numNetwork; ++__){
            string p1, p2;
            cin >> p1 >> p2;

            if(rootMap.find(p1) == rootMap.end()){
                rootMap[p1] = p1;
                memberCnt[p1] = 1;
            }
            if(rootMap.find(p2) == rootMap.end()){
                rootMap[p2] = p2;
                memberCnt[p2] = 1;
            }

            const string root_of_p1 = findRoot(p1);
            const string root_of_p2 = findRoot(p2);

            if(root_of_p1 == root_of_p2){
                cout << memberCnt[root_of_p1] << '\n';
                continue;
            }

            const string& parent = min(root_of_p1, root_of_p2);
            const string& child = max(root_of_p1, root_of_p2);

            rootMap[child] = parent;

            memberCnt[parent] += memberCnt[child];
            memberCnt[child] = 0;

            cout << memberCnt[parent] << '\n';
        }
    }

    return 0;
}
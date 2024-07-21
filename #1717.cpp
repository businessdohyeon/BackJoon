/*
BackJoon No.
#1717
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 요소별 속해있는 집함
    int set[n+1];
    // 집합별 속해있는 요소들
    vector<int> element[n+1];
    for(int i=0; i<=n; ++i){
        set[i] = i;
        element[i].push_back(i);
    }

    for(int _=0; _<m; ++_){
        int command, a, b;
        cin >> command >> a >> b;

        int set_of_a = set[a];
        int set_of_b = set[b];
        if(command == 0){
            if(set_of_a == set_of_b)      continue;

            int mother, child;
            if(element[set_of_a].size() > element[set_of_b].size()){
                mother = set_of_a;
                child = set_of_b;
            }else{
                mother = set_of_b;
                child = set_of_a;
            }
            
            for(auto e : element[child]){
                element[mother].push_back(e);
                set[e] = mother;
            }
            element[child].clear();
            element[child].shrink_to_fit();
        }else{
            if(set_of_a == set_of_b)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }

    return 0;
}
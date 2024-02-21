/*
BaekJoon No
#1764
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    int n, m;
    cin >> n >> m;

    set<string> haveNotHear;
    for(int i=0; i<n; ++i){
        string input;
        cin >> input;
        haveNotHear.insert(input);
    }

    set<string> result;
    for(int i=0; i<m; ++i){
        string input;
        cin >> input;
        auto itr = haveNotHear.find(input);
        if(itr != haveNotHear.end())
            result.insert(*itr);
    }

    cout << result.size() << '\n';
    for(auto itr = result.begin(); itr != result.end(); ++itr)
        cout << *itr << '\n';    

    return 0;
}
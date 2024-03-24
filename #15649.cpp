/*
BaekJoon No
#15649
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void permutaion(int max, int len, vector<int> result, bool isExist[]){
    if(result.size() >= len){
        for(int e: result)
            cout << e << ' ';
        cout << '\n';
        return;
    }

    for(int i=1; i<=max; ++i){
        if(isExist[i])  continue;

        result.push_back(i);
        isExist[i] = true;

        permutaion(max, len, result, isExist);

        result.pop_back();
        isExist[i] = false;
    }
}


int main(){
    setDefault();

    int n, m;
    cin >> n >> m;

    vector<int> result;
    bool isExist[n+1];
    fill(isExist, isExist+n+1, false);

    permutaion(n, m, result, isExist);

    return 0;
}
/*
BaekJoon No
#15650
*/

#include <iostream>
#include <vector>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void combination(int n, int r, vector<int>* p_result, int start){
    int sizeOfResult = (*p_result).size();
    
    if(sizeOfResult == r){
        for(auto e : (*p_result))
            cout << e << ' ';
        cout << '\n';
        return;
    }
    
    int max = n-(r-sizeOfResult) + 1;
    for(int i=start; i<=max; ++i){
        (*p_result).push_back(i);
        combination(n, r, p_result, i+1);
        (*p_result).pop_back();
    }
}

int main(){
    setDefault();

    int n, m;
    cin >> n >> m;

    vector<int> result;
    combination(n, m, &result, 1);

    return 0;
}
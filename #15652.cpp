/*
BaekJoon No
#15652
*/

#include <iostream>
#include <vector>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void process(int n, int m, vector<int>* p_result){
    if(p_result->size() == m){
        for(auto num : *p_result)
            cout << num << ' ';
        cout << '\n';
        return;
    }
    
    for(int i=1; i<=n; ++i){
        if(!p_result->empty() && i < p_result->back())
            continue;

        p_result->push_back(i);
        process(n, m, p_result);
        p_result->pop_back();
    }
}

int main(){
    setDefault();

    int n, m;
    cin >> n >> m;

    vector<int> result;
    process(n, m, &result);

    return 0;
}
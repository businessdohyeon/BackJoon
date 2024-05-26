/*
BackJoon No.
#17299
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;
    
    int input[size];
    int cnt[1000001] = {0};
    for(int i=0; i<size; ++i){
        cin >> input[i];
        ++cnt[input[i]];
    }

    int ans[size];
    fill(ans, ans+size, -1);

    vector<int> v;
    for(int i=0; i<size; ++i){
        while(!v.empty() && cnt[input[v.back()]] < cnt[input[i]]){
            ans[v.back()] = input[i];
            v.pop_back();
        }
        v.push_back(i);
    }
    
    for(auto e : ans)
        cout << e << " ";

    return 0;
}
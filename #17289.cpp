/*
BackJoon No.
#17289
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
    for(int i=0; i<size; ++i)
        cin >> input[i];

    int ans[size];
    fill(ans, ans+size, -1);

    vector<int> v;
    for(int i=0; i<size; ++i){
        if(i==0){
            v.push_back(i);
        }else{
            while(!v.empty() && input[v.back()] < input[i]){
                ans[v.back()] = input[i];
                v.pop_back();
            }
            v.push_back(i);
        }
    }

    for(auto e : ans)
        cout << e << " ";
    
    return 0;
}
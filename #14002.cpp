/*
BackJoon No.
#14002
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int s[n];
    for(int i=0; i<n; ++i)
        cin >> s[i];

    vector<int> dp[n];
    vector<int> *ans = nullptr;
    for(int i=0; i<n; ++i){
        vector<int> *target = nullptr;
        for(int j=0; j<i; ++j){
            if(s[j] >= s[i])    continue;
            if(target == nullptr 
                || dp[j].size() > target->size()
                || (dp[j].size() == target->size() && dp[j].back() < target->back()) ){
                target = &dp[j];
            }
        }

        if(target != nullptr)
            dp[i] = *target;
        dp[i].push_back(s[i]);

        if(ans == nullptr || ans->size() < dp[i].size())
            ans = &dp[i];
    }

    cout << ans->size() << '\n';
    for(auto e : *ans)
        cout << e << " ";

    return 0;
}
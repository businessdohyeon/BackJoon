/*
BackJoon No.
#14003
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> s(n);
    for(int &e : s)
        cin >> e;

    vector<int> dp(n);
    dp[0] = 1;

    int maxLen = dp[0];
    int idxOfLastElem=0;

    vector<int> v;
    v.push_back(s[0]);
    for(int i=1; i<n; ++i){
        if(s[i] > v.back()){
            v.push_back(s[i]);
            dp[i] = v.size();
        }else{
            auto p = lower_bound(v.begin(), v.end(), s[i]);
            *p = s[i];
            dp[i] = p - v.begin() + 1;
        }

        if(dp[i] > maxLen){
            idxOfLastElem = i;
            maxLen = dp[i];
        }
    }

    deque<int> idxOfLIS;
    idxOfLIS.push_back(idxOfLastElem);
    for(int i=idxOfLastElem-1; i>=0; --i)
        if(s[i] < s[idxOfLIS.front()] && dp[i] == dp[idxOfLIS.front()]-1)
            idxOfLIS.push_front(i);

    cout << maxLen << '\n';
    for(auto e : idxOfLIS)
        cout << s[e] << ' ';

    return 0;
}
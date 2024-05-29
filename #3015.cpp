/*
BackJoon No.
#3015
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int s[n];
    for(int i=0; i<n; ++i)
        cin >> s[i];

    long long ans = 0;
    vector<pair<int, int> > stack;
    for(int i=0; i<n; ++i){
        int cnt = 1;
        while(!stack.empty() && stack.back().first <= s[i]){
            ans += stack.back().second;
            if(stack.back().first == s[i])
                cnt += stack.back().second;
            stack.pop_back();
        }
        if(!stack.empty())
        ++ans;
        stack.push_back(make_pair(s[i], cnt));
    }

    cout << ans;
    
    return 0;
}
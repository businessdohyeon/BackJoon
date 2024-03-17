/*
BaekJoon No
#20920
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool comp(pair<string, int> a, pair<string, int> b){
    if(a.second != b.second)    
        return (a.second > b.second);

    int a_len = a.first.length();
    int b_len = b.first.length();
    if(a_len != b_len)
        return a_len > b_len;
        
    return a.first < b.first;
}

int main(){
    setDefault();

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> word_cnt_map;
    for(int i=0; i<n; ++i){
        string input;
        cin >> input;

        if(input.length() < m)  continue;

        if(word_cnt_map.find(input) == word_cnt_map.end())
            word_cnt_map[input] = 0;
        
        ++word_cnt_map[input];
    }

    vector<pair<string,int>> v;
    for(auto element : word_cnt_map)
        v.push_back(element);

    sort(v.begin(), v.end(), comp);

    for(auto a : v)
        cout << a.first << '\n';

    return 0;
}
/*
BackJoon No.
#2667
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
bool s[25][25];
vector<vector<int> > graph(1000000);
int cnt;
bool visited[100000];
vector<int> ans;

void dfs(int start){
    if(visited[start])  return;

    visited[start] = true;
    ++cnt;

    for(auto e : graph[start])
        if(!visited[e])
            dfs(e);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    string tmp[n];
    for(int i=0; i<n; ++i)
        cin >> tmp[i];
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(tmp[i][j] == '0')
                s[i][j] = false;
            else
                s[i][j] = true;
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(!s[i][j])    continue;
            
            int v1 = n*i+j;
            if(i>0 && s[i-1][j]){
                int v2 = n*(i-1)+j;
                graph[v1].push_back(v2);
                graph[v2].push_back(v1);
            }
            if(i<n-1 && s[i+1][j]){
                int v2 = n*(i+1)+j;
                graph[v1].push_back(v2);
                graph[v2].push_back(v1);
            }
            if(j>0 && s[i][j-1]){
                int v2 = n*i+j-1;
                graph[v1].push_back(v2);
                graph[v2].push_back(v1);
            }
            if(j<n-1 && s[i][j+1]){
                int v2 = n*i+j+1;
                graph[v1].push_back(v2);
                graph[v2].push_back(v1);
            }
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(s[i][j] == 0)    continue;

            cnt = 0;

            dfs(n*i+j);

            if(cnt != 0)
                ans.push_back(cnt);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';

    for(auto e : ans)
        cout << e << '\n';

    return 0;
}
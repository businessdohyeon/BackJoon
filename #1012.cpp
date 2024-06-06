/*
BackJoon No.
#1012
*/

#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<pair<int,int> > graph[50][50];
bool visited[50][50];

void dfs(int x, int y){
    visited[x][y] = true;

    for(auto e : graph[x][y])
        if(!visited[e.first][e.second])
            dfs(e.first, e.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int i=0; i<t; ++i){
        int width, height, num;
        cin >> width >> height >> num;

        bool board[width][height];
        for(int x=0; x<width; ++x)
            for(int y=0; y<height; ++y)
                board[x][y] = false;

        for(int j=0; j<num; ++j){
            int x, y;
            cin >> x >> y;
            board[x][y] = true;
        }

        for(int x=0; x<width; ++x){
            for(int y=0; y<height; ++y){
                if(!board[x][y])    continue;

                for(int j=0; j<4; ++j){
                    if(x+dx[j]>=0 && x+dx[j]<width && y+dy[j]>=0 && y+dy[j]<height && board[x+dx[j]][y+dy[j]]){
                        graph[x][y].push_back(make_pair(x+dx[j], y+dy[j]));
                        graph[x+dx[j]][y+dy[j]].push_back(make_pair(x, y));
                    }
                }
            }
        }

        int cnt = 0;
        for(int x=0; x<width; ++x){
            for(int y=0; y<height; ++y){
                if(board[x][y] && !visited[x][y]){
                    dfs(x, y);
                    ++cnt;
                }
            }
        }

        cout << cnt << '\n';

        for(int x=0; x<width; ++x){
            for(int y=0; y<height; ++y){
                graph[x][y].clear();
                visited[x][y] = false;
            }
        }
    }

    return 0;
}
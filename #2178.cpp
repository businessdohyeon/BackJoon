/*
BackJoon No.
#2178
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int width, hegiht;
vector<pair<int,int> > graph[100][100];
bool visited[100][100];
int cnt;
int ans;

void bfs(queue<pair<int, int> > q){
    if(q.empty() || ans != 0)   return;
    
    queue<pair<int, int> > nextq;
    while(!q.empty()){
        pair<int, int> front = q.front();
        q.pop();

        int x = front.first;
        int y = front.second;

        if(visited[x][y])
            continue;

        visited[x][y] = true;
        if(x == width-1 && y == hegiht-1){
            ans = cnt;
            return;
        }

        for(auto e : graph[x][y])
            nextq.push(make_pair(e.first, e.second));
    }

    ++cnt;
    bfs(nextq);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> width >> hegiht;

    string input[width];
    for(int i=0; i<width; ++i)
        cin >> input[i];

    for(int x=0; x<width; ++x){
        for(int y=0; y<hegiht; ++y){
            for(int tmp=0; tmp<4; ++tmp){
                int targetX = x+dx[tmp];
                int targetY = y+dy[tmp];

                if(input[x][y] == '0' || targetX<0 || targetX>=width || targetY<0 || targetY>=hegiht || input[targetX][targetY] == '0')
                    continue;

                graph[targetX][targetY].push_back(make_pair(x, y));
                graph[x][y].push_back(make_pair(targetX, targetY));
            }
        }
    }

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    bfs(q);

    cout << ans+1;

    return 0;
}

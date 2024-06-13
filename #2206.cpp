/*
BackJoon No.
#2206
*/

#include <iostream>
#include <deque>

using namespace std;

class Item{
public:
    int x, y;
    bool haveBrokenWall;
    Item(int x, int y, bool haveBrokenWall){
        this->x = x;
        this->y = y;
        this->haveBrokenWall = haveBrokenWall;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    int width, height;
    cin >> height >> width;

    string wall[height];
    for(int y=0; y<height; ++y)
        cin >> wall[y];
    
    bool isVisited[width][height][2];
    for(int x=0; x<width; ++x)
        for(int y=0; y<height; ++y)
            for(int mode=0; mode<2; ++mode)
                isVisited[x][y][mode] = false;

    deque<Item> dq;
    Item firstItem(0, 0, false);
    dq.push_back(firstItem);
    
    int cnt = 1;
    int size = 1;
    while(!dq.empty()){
        auto front = dq.front();
        dq.pop_front();
        --size;

        if(front.x == width-1 && front.y == height-1){
            cout << cnt;
            return 0;
        }

        if(front.haveBrokenWall){
            if(!isVisited[front.x][front.y][1]){
                isVisited[front.x][front.y][1] = true;

                for(int dirct=0; dirct<4; ++dirct){
                    int x = front.x + dx[dirct];
                    int y = front.y + dy[dirct];

                    if(x<0 || x>=width || y<0 || y>=height || isVisited[x][y][1] || wall[y][x] == '1')
                        continue;
                    
                    Item tmp(x, y, front.haveBrokenWall);
                    dq.push_back(tmp);
                }
            }
        }else{
            if(!isVisited[front.x][front.y][0]){
                isVisited[front.x][front.y][0] = true;

                for(int dirct=0; dirct<4; ++dirct){
                    int x = front.x + dx[dirct];
                    int y = front.y + dy[dirct];

                    if(x<0 || x>=width || y<0 || y>=height || isVisited[x][y][0])
                        continue;
                    
                    Item tmp(x, y, front.haveBrokenWall);
                    if(wall[y][x] == '1')
                        tmp.haveBrokenWall = true;
                    dq.push_back(tmp);
                }
            }
        }

        if(size == 0){
            size = dq.size();
            ++cnt;
        }
    }

    cout << -1;

    return 0;
}
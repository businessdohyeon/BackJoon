/*
BackJoon No.
#7569
*/

#include <iostream>
#include <deque>

using namespace std;

const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};

class Pos{
public:
    int x, y, z;
    Pos(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int width, depth, height;
    cin >> width >> depth >> height;

    deque<Pos> dq1, dq2;
    deque<Pos> *cur = &dq1, *next = &dq2;

    int tomato[width][depth][height];
    for(int z=0; z<height; ++z)
        for(int y=0; y<depth; ++y)
            for(int x=0; x<width; ++x)
                cin >> tomato[x][y][z];

    for(int z=0; z<height; ++z)
        for(int y=0; y<depth; ++y)
            for(int x=0; x<width; ++x)
                if(tomato[x][y][z] == 1)
                    for(int direction=0; direction<6; ++direction){
                        int newX = x + dx[direction];
                        int newY = y + dy[direction];
                        int newZ = z + dz[direction];
                        if(newX<0 || newX>=width 
                            || newY<0 || newY>= depth 
                            || newZ<0 || newZ>= height
                            || tomato[newX][newY][newZ] != 0)
                            continue;
                        Pos tmp(newX, newY, newZ);
                        cur->push_back(tmp);
                    }

    int cnt = 0;
    bool isActivated = false;
    while(!cur->empty()){
        Pos front = cur->front();
        cur->pop_front();

        if(tomato[front.x][front.y][front.z] == 0){
            tomato[front.x][front.y][front.z] = 1;
            isActivated = true;

            for(int direction=0; direction<6; ++direction){
                int newX = front.x + dx[direction];
                int newY = front.y + dy[direction];
                int newZ = front.z + dz[direction];
                if(newX<0 || newX>=width 
                    || newY<0 || newY>= depth 
                    || newZ<0 || newZ>= height 
                    || tomato[newX][newY][newZ] != 0)
                    continue;
                Pos tmp(newX, newY, newZ);
                next->push_back(tmp);
            }
        }

        if(cur->empty()){
            swap(cur, next);
            if(isActivated){
                ++cnt;
                isActivated = false;
            }
        }
    }

    for(int z=0; z<height; ++z)
        for(int y=0; y<depth; ++y)
            for(int x=0; x<width; ++x)
                if(tomato[x][y][z] == 0){
                    cout << -1;
                    return 0;
                }

    cout << cnt;

    return 0;
}
/*
BackJoonN No.
#7576
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    int width, height;
    cin >> width >> height;

    int tomato[width][height];
    vector<pair<int, int> > rippen;
    for(int y=0; y<height; ++y){
        for(int x=0; x<width; ++x){
            cin >> tomato[x][y];
            if(tomato[x][y] == 1)
                rippen.push_back(make_pair(x, y));
        }
    }

    deque<pair<int, int> > dq1, dq2;
    deque<pair<int, int> > *cur = &dq1, *next = &dq2;  

    for(auto e : rippen){
        for(int direction = 0; direction < 4; ++direction){
            int x = e.first + dx[direction];
            int y = e.second + dy[direction];

            if(x < 0 || x >=  width || y < 0 || y >= height)    continue;

            if(tomato[x][y] == 0)
                dq1.push_back(make_pair(x, y));
        }
    }

    int cnt = 0;
    bool activated = false;
    while (!cur->empty()){
        auto front = cur->front();
        cur->pop_front();

        if(tomato[front.first][front.second] == 0){
            activated = true;
            tomato[front.first][front.second] = 1;

            for(int direction = 0; direction < 4; ++direction){
                int x = front.first + dx[direction];
                int y = front.second + dy[direction];

                if(x < 0 || x >=  width || y < 0 || y >= height)    continue;

                if(tomato[x][y] == 0)
                    next->push_back(make_pair(x, y));
            }
        }

        if(cur->empty()){
            swap(cur, next);
            if(activated){
                ++cnt;
                activated = false;
            }
        }
    }

    for(int y=0; y<height; ++y){
        for(int x=0; x<width; ++x){
            if(tomato[x][y] == 0){
                cout << -1;
                return 0;
            }
        }
    }

    cout << cnt;

    return 0;
}
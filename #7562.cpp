/*
BackJoon No.
#7562
*/

#include <iostream>
#include <deque>

using namespace std;

const int dx[] = {-1, -2, -1, -2, 1, 2, 1, 2};
const int dy[] = {-2, -1, 2, 1, -2, -1, 2, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; ++i){
        int size, x1, x2, y1, y2;
        cin >> size;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        bool visited[size][size];
        for(int x=0; x<size; ++x)
            for(int y=0; y<size; ++y)
                visited[x][y] = false;

        deque<pair<int, int> > dq1, dq2;
        deque<pair<int, int> > *cur = &dq1, *next = &dq2;
        dq1.push_back(make_pair(x1, y1));

        int ans;
        int cnt = 0;
        while(!cur->empty()){
            pair<int, int> front = cur->front();
            cur->pop_front();

            if(!visited[front.first][front.second]){
                visited[front.first][front.second] = true;

                if(front.first == x2 && front.second == y2){
                    ans = cnt;
                    break;
                }

                for(int j=0; j<8; ++j){
                    int x = front.first + dx[j];
                    int y = front.second + dy[j];
                    if(x < 0 || x >= size || y < 0 || y >= size)
                        continue;
                    if(!visited[x][y])
                        next->push_back(make_pair(x, y));
                }
            }

            if(cur->empty()){
                swap(cur, next);
                ++cnt;
            }
        }

        cout << ans << '\n';

    }

    return 0;
}
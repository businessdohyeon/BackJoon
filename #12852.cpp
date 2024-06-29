/*
BackJoon No
#12852
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int DIVISOR[] = {3, 2, 1};
    const int BIAS[] = {0, 0, -1};

    int x;
    cin >> x;

    bool isVisited[x+1];
    fill(isVisited, isVisited+x+1, false);

    queue<vector<int> > q;
    q.push({x});
    while(true){
        vector<int> front = q.front();
        int curNum = front.back();
        q.pop();

        if(isVisited[curNum])  continue;

        if(curNum == 1){
            cout << front.size()-1 << '\n';
            for(auto e : front)
                cout << e << ' ';
            break;
        }

        isVisited[curNum] = true;
        for(int i=0; i<3; ++i){
            int nextNum = curNum/DIVISOR[i] + BIAS[i];
            if(curNum % DIVISOR[i] == 0 && !isVisited[nextNum])
                q.emplace(front).push_back(nextNum);
        }
    }

    return 0;
}
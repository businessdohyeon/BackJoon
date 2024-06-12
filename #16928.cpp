/*
BackJoon No.
#16928
*/

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    int graph[101];
    fill(graph, graph+101, -1);
    for(int i=0; i<n+m; ++i){
        int x, y;
        cin >> x >> y;
        graph[x] = y;
    }

    int visited[101];
    fill(visited, visited+101, -1);
    visited[1] = 0;

    deque<int> dq;
    dq.push_back(1);

    while(!dq.empty()){
        int front = dq.front();
        dq.pop_front();

        if(front == 100)    break;

        for(int i=1; i<=6; ++i){
            int pos = front+i;

            if(pos<0 || pos>100)    continue;

            while(graph[pos] != -1)
                pos = graph[pos];

            if(visited[pos] == -1 || visited[front]+1 < visited[pos]){
                visited[pos] = visited[front]+1;
                dq.push_back(pos);
            }
        }
    }

    cout << visited[100];

    return 0;
}
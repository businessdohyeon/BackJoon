/*
BackJoon No.
#9019
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int MAX = 10000;

    int t;
    cin >> t;

    for(int _=0; _<t; ++_){
        int input, output;
        cin >> input >> output;

        // { op, previousValue }
        pair<char, int> prev[MAX];
        fill(prev, prev+MAX, make_pair('\0', -1));
        prev[input] = make_pair('!', -2);

        deque<int> dq;
        dq.push_back(input);
        while(!dq.empty()){
            int front = dq.front();
            dq.pop_front();

            // { op, nextValue}
            vector<pair<char, int> > next = {
                {'D', 2*front % MAX}, 
                {'S', front == 0 ? MAX-1 : front-1}, 
                {'L', (front%1000 * 10) + (front/1000)}, 
                {'R', (front%10 * 1000) + (front/10)}
            };
            for(auto& e : next){
                if(prev[e.second].second != -1
                        || e.first == 'L' && prev[front].first == 'L' && prev[prev[front].second].first == 'L'
                        || e.first == 'R' && prev[front].first == 'R' && prev[prev[front].second].first == 'R'){
                    continue;
                }
                prev[e.second] = make_pair(e.first, front);

                if(e.second == output)  break;

                dq.push_back(e.second);
            }
        }

        deque<char> path;
        for(int i=output; i != input; i = prev[i].second)
            path.push_front(prev[i].first);

        for(auto e : path)
            cout << e;
        cout << '\n';
    }

    return 0;
}
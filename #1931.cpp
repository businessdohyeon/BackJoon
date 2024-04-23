/*
BaekJoon No
#1931
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool comp(pair<int, int> a, pair<int, int> b){
    if(b.second == a.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(){
    setDefault();

    int n;
    cin >> n;

    vector<pair<int, int> > meeting;
    for(int i=0; i<n; ++i){
        int startTime, endTime;
        cin >> startTime >> endTime;
        meeting.push_back(make_pair(startTime, endTime));
    }

    sort(meeting.begin(), meeting.end(), comp);

    int cnt = 0;
    int endedAt = 0;
    for(auto e:meeting){
        if(e.first >= endedAt){
            endedAt = e.second;
            ++cnt;
        }
    }

    cout << cnt;

    return 0;
}
/*
BackJoon No
#1450
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makeCombination(int s[], int start, int end, int limit, vector<int> &result){
    result.push_back(0);

    for(int i=start; i<=end; ++i){
        int size = result.size();
        for(int j=0; j<size; ++j){
            int cal = result[j] + s[i];
            if(cal <= limit)
                result.push_back(cal);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, limit;
    cin >> n >> limit;

    int s[n];
    for(int i=0; i<n; ++i)
        cin >> s[i];

    vector<int> c1, c2;

    int mid = n/2;
    makeCombination(s, 0, mid-1, limit, c1);
    makeCombination(s, mid, n-1, limit, c2);

    sort(c2.begin(), c2.end());

    long long cnt = 0;
    for(int e : c1)
        cnt += upper_bound(c2.begin(), c2.end(), limit-e) - c2.begin();

    cout << cnt;

    return 0;
}
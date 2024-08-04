/*
BackJoon No.
#10250
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testNum;
    cin >> testNum;

    for(int _=0; _<testNum; ++_){
        int h, w, n;
        cin >> h >> w >> n;
        
        int floor = n%h == 0 ? h : n%h;
        int roomNum = n%h == 0 ? n/h : n/h+1;
        cout << floor*100 + roomNum << '\n';
    }

    return 0;
}
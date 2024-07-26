/*
BackJoon No.
#9372
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
        int nationNum, airplaneNum;
        cin >> nationNum >> airplaneNum;

        for(int __=0; __<airplaneNum; ++__){
            int v1, v2;
            cin >> v1 >> v2;
        }

        cout << nationNum-1 << '\n';
    }

    return 0;
}
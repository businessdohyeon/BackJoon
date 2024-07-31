/*
BackJoon No.
#31403
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testNum;
    cin >> testNum;

    for(int _=0; _<testNum; ++_){
        string test;
        cin >> test;

        int total = 0;
        int score = 0;
        for(auto ch : test){
            if(ch == 'O'){
                ++score;
                total += score;
            }else{
                score = 0;
            }
        }
        
        cout << total << '\n';
    }

    return 0;
}
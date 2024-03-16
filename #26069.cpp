/*
BaekJoon No
#26069
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    set<string> dancingPeople;
    dancingPeople.insert("ChongChong");
    
    for(int i=0; i<n; ++i){
        string a, b;
        cin >> a >> b;

        bool is_A_Dancing = dancingPeople.find(a) != dancingPeople.end();
        bool is_B_Dancing = dancingPeople.find(b) != dancingPeople.end();

        if(is_A_Dancing != is_B_Dancing){
            dancingPeople.insert(a);
            dancingPeople.insert(b);
        }
    }

    cout << dancingPeople.size();

    return 0;
}
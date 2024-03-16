/*
BaekJoon No
#25192
*/

#include <iostream>
#include <string>
#include <unordered_set>

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

    int cnt = 0;
    unordered_set<string> peopleUsedEmoji;
    for(int i=0; i<n; ++i){
        string input;
        cin >> input;

        if(input != "ENTER")
            peopleUsedEmoji.insert(input);

        if(i == n-1 || input == "ENTER"){
            cnt += peopleUsedEmoji.size();
            peopleUsedEmoji.erase(peopleUsedEmoji.begin(), peopleUsedEmoji.end());
        }
    }

    cout << cnt;

    return 0;
}
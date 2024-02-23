/*
BaekJoon No
#11478
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

    string input;
    cin >> input;

    int len = input.length();

    unordered_set<string> result;
    for(int i=1; i<=len; ++i)
        for(int j=0; j+i<=len; ++j)
            result.insert(input.substr(j, i));

    cout << result.size();

    return 0;
}
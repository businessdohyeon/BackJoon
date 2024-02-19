/*
BaekJoon No
#1620
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> book;
    string input;
    for(int i=0; i<n; ++i){
        cin >> input;
        string index = to_string(i+1);
        book[input] = index;
        book[index] = input;
    }

    for(int i=0; i<m; ++i){
        cin >> input;
        cout << book[input] << '\n';
    }


    return 0;
}
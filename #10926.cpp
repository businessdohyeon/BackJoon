/*
BaekJoon No
#10926
*/

#include <iostream>
#include <string>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    string name;
    cin >> name;
    cout << name + "??!";

    return 0;
}
/*
BackJoon No.
#1076
*/

#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

long long getValue(string& str){
    if(str == "black")              return 0;
    else if(str == "brown")         return 1;
    else if(str == "red")           return 2;
    else if(str == "orange")        return 3;
    else if(str == "yellow")        return 4;
    else if(str == "green")         return 5;
    else if(str == "blue")          return 6;
    else if(str == "violet")        return 7;
    else if(str == "grey")          return 8;
    else if(str == "white")         return 9;
    else                            return -1;
}
long long getMultiplier(string& str){
    int value = getValue(str);
    return pow(10, value);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;

    cout << (10*getValue(str1) + getValue(str2))*getMultiplier(str3);

    return 0;
}
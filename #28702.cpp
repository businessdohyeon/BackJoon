/*
BackJoon No.
#28702
*/

#include <iostream>
#include <string>

using namespace std;

int tryStringToInt(const string& str){
    int result = 0;
    for(int digit=str.size()-1, weight = 1; digit>=0; --digit, weight *= 10){
        if(str[digit] < '0' || str[digit] > '9')    return -1;
        result += int(str[digit]-'0') * weight;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str[3];
    for(int i=0; i<3; ++i)
        cin >> str[i];

    int target;
    for(int i=0; i<3; ++i){
        int result = tryStringToInt(str[i]);
        if(result != -1){
            target = result + (3-i);
            break;
        }
    }

    string ans = "";
    if(target % 3 == 0)     ans += "Fizz";
    if(target % 5 == 0)     ans += "Buzz";

    if(ans == "")   cout << target;
    else            cout << ans;

    return 0;
}
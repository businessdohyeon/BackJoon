/*
BackJoon No
#9935
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str, bomb;
    cin >> str >> bomb;

    string result = "";
    for(int i=0; i<str.length(); ++i){
        if(i >= bomb.length()-1 && str[i] == bomb.back() && result.length() >= bomb.length()-1){
            bool flag = true;
            for(int j=result.length()-1, k=bomb.length()-2; k>=0; --j, --k){
                if(result[j] != bomb[k]){
                    flag = false;
                    break;
                }
            }

            if(flag)
                for(int tmp=0; tmp<bomb.length()-1; ++tmp)
                    result.pop_back();
            else
                result.push_back(str[i]);
        }else{
            result.push_back(str[i]);
        }
    }

    if(result.length() == 0)    cout << "FRULA";
    else                        cout << result;

    return 0;
}
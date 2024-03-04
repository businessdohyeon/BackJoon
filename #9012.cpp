/*
BaekJoon No
#9012
*/

#include <iostream>
#include <string>
#include <vector>

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

    for(int i=0; i<n; ++i){
        string input;
        cin >> input;

        int len = input.length();
        vector<bool> stack;
        string result = "YES";

        for(int j=0; j<len; ++j){
            if(input[j] == '('){
                stack.push_back(true);
            }else if(input[j] == ')'){
                if(stack.empty()){
                    result = "NO";
                    break;
                }
                stack.pop_back();
            }
        }

        if(!stack.empty())  result = "NO";

        cout << result << '\n';
    }


    return 0;
}
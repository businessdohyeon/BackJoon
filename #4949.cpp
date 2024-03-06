/*
BaekJoon No
#4949
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

bool isBalancedString(string str){
    vector<char> stack;
    int len = str.size();

    for(int i=0; i<len; ++i){
        switch(str[i]){
            case '(':
            case '[':
                stack.push_back(str[i]);
                break;
            case ')':
                if(!stack.empty() && stack.back() == '(')       
                    stack.pop_back();
                else                                            
                    return false;
                break;
            
            case ']':
                if(!stack.empty() && stack.back() == '[')       
                    stack.pop_back();
                else                                            
                    return false;
                break;
            default:
                break;
        }
    }

    if(!stack.empty())  return false;
    
    return true;
};


int main(){
    setDefault();

    while(true){
        string input;
        getline(cin, input);

        if(input == ".")    break;

        string result = isBalancedString(input) ? "yes" : "no";
        cout << result << '\n';
    }

    return 0;
}
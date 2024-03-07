/*
BaekJoon No
#12789
*/

#include <iostream>
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

    vector<int> stack;
    int expectedValue = 1;

    for(int i=0; i<n; ++i){
        int input;
        cin >> input;
        
        if(input == expectedValue)
            ++expectedValue;
        else
            stack.push_back(input);
        
        while(!stack.empty() && stack.back() == expectedValue){
            stack.pop_back();
            ++expectedValue;
        }
    }

    if(stack.empty())   cout << "Nice";
    else                cout << "Sad";

    return 0;
}
/*
BaekJoon No
#10773
*/

#include <iostream>
#include <vector>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Stack {
    private: 
        vector<int> data;
    public:
        void push(int n){
            data.push_back(n);
        };
        void pop(){
            data.pop_back();
        };
        int getSum(){
            int result = 0;
            for(int element : data) 
                result += element;
            return result;
        };
};


int main(){
    setDefault();

    int n;
    cin >> n;

    Stack stack;

    for(int i=0; i<n; ++i){
        int input;
        cin >> input;
        if(input)   stack.push(input);
        else        stack.pop();
    }

    cout << stack.getSum();

    return 0;
}
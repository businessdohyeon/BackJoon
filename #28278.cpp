/*
BaekJoon No
#28278
*/

#include <iostream>
#include <vector>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Stack{
    private:
        vector<int> data;
    public:
        int size(){
            return data.size();
        };
        bool isEmpty(){
            return data.empty();
        };
        void push(int n){
            data.push_back(n);
        };
        int top(){
            if(isEmpty())  return -1;
            return data.back();
        };
        int pop(){
            if(isEmpty())  return -1;

            int target = data.back();
            data.pop_back();
            return target;
        };
};

int main(){
    setDefault();

    int n;
    cin >> n;

    Stack stack;

    for(int i=0; i<n; ++i){
        int action;
        cin >> action;

        switch(action){
            case 1:
                int input;
                cin >> input;
                stack.push(input);
                break;
            case 2:
                cout << stack.pop() << '\n';
                break;
            case 3:
                cout << stack.size() << '\n';
                break;
            case 4:
                cout << stack.isEmpty() << '\n';
                break;
            case 5:
                cout << stack.top() << '\n';
                break;
            default:
                cout << "exeptional case";
                break;
        }
    }

    return 0;
}
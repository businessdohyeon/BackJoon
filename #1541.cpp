/*
BaekJoon No
#1541
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

    string input;
    cin >> input;
    
    vector<int> numArr;
    vector<char> opArr;
    int tmp = 0;
    int inputLen = input.length();
    for(int i=0; i<inputLen; ++i){
        char ch = input[i];
        if (i == inputLen-1){
            tmp = tmp*10 + int(ch-'0');
            numArr.push_back(tmp);
            tmp = 0;
        }else if(ch == '+' || ch == '-'){
            numArr.push_back(tmp);
            opArr.push_back(ch);
            tmp = 0;
        }else{
            tmp = tmp*10 + int(ch-'0');
        }
    }

    int opArrSize = opArr.size();
    for(int i=opArrSize-1; i>=0; --i){
        if(opArr[i] == '+'){
            numArr[i] += numArr[i+1];
            numArr[i+1] = 0;  
        }
    }

    int result = numArr[0];
    for(int i=0; i<opArrSize; ++i){
        if(opArr[i] == '-'){
            result -= numArr[i+1];
        }
    }
    cout << result;

    return 0;
}
/*
BaekJoon No
#2903
*/

#include <iostream>
#include <cmath>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    int sqrtResult, former; 
    sqrtResult = 2;     //first Value

    for(int i=0; i <n; ++i){
        former = sqrtResult;
        sqrtResult = 2*former -1;
    }
    
    int result = pow(sqrtResult, 2);

    cout << result;
    
    return 0;
}
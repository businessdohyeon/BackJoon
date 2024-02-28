/*
BaekJoon No
#4948
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool isPrimeNumber(int n){
    if(n == 0 || n == 1)    return false;
    for(int i=2; i*i<=n; ++i)
        if(n%i == 0)        return false;
    return true;
}

int countPrimeNumberBetween(int a, int b){
    bool isNotPrimeNumberArray[b+1] = {0};
    isNotPrimeNumberArray[0] = true;
    isNotPrimeNumberArray[1] = true;

    for(int i=2; i<=b; ++i){
        if(isNotPrimeNumberArray[i])    continue;

        if(!isPrimeNumber(i))           
            isNotPrimeNumberArray[i] = true;

        for(int j=2; i*j<=b; ++j)       
            isNotPrimeNumberArray[i*j] = true;
    }
    
    int cnt = 0;
    for(int i=a; i<=b; ++i)
        if(!isNotPrimeNumberArray[i])   ++cnt;
    return cnt;
}

int main(){
    setDefault();

    while(true){
        int input;
        cin >> input;

        if(input == 0)  break;

        cout << countPrimeNumberBetween(input+1, 2*input) << '\n';
    }

    return 0;
}
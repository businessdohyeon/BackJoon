/*
BaekJoon No
#24416
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int cntRecursion = 0, cntDynamic = 0;

int fibonacciRecursion(int n){
    if(n==1 || n==2){
        ++cntRecursion;
        return 1;
    }else{
        return fibonacciRecursion(n-2)+fibonacciRecursion(n-1);
    }
}
int fibonacciDynamic(int n){
    int arr[n];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2; i<n; ++i){
        arr[i] = arr[i-2]+arr[i-1];
        ++cntDynamic;
    }
    return arr[n-1];
}

int main(){
    setDefault();

    int n;
    cin >> n;

    fibonacciRecursion(n);
    fibonacciDynamic(n);

    cout << cntRecursion << ' ' << cntDynamic;

    return 0;
}
/*
BackJoon No.
#2475
*/

#include <iostream>
#include <math.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int input[5];
    for(int i=0; i<5; ++i)
        cin >> input[i];
    
    int validation = 0;
    for(int i=0; i<5; ++i)
        validation += pow(input[i], 2);
    validation %= 10;

    cout << validation;

    return 0;
}
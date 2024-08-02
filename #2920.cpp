/*
BackJoon No.
#2920
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int input[8];
    for(int i=0; i<8; ++i)
        cin >> input[i];

    bool isAscending = true;
    bool isDescending = true;
    for(int i=0; i<7; ++i){
        if(input[i+1] != input[i]+1)
            isAscending = false;
        if(input[i+1] != input[i]-1)
            isDescending = false;
    }

    if(isAscending)         cout << "ascending";
    else if(isDescending)   cout << "descending";
    else                    cout << "mixed";

    return 0;
}
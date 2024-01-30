/*
BaekJoon No
#5086
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    while(true){
        int a, b;
        cin >> a >> b;
        if(a==0 && b==0)    break;

        if(b%a==0){
            cout << "factor" << '\n';
        }else if(a%b==0){
            cout << "multiple" << '\n';
        }else{
            cout << "neither" << '\n';
        }
    }

    return 0;
}
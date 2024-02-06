/*
BaekJoon No
#2587
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    // setDefault();

    int s[5];
    for(int i=0; i<5; ++i)
        cin >> s[i];
    
    for(int i=0; i<4; ++i){
        for(int j = i+1; j<5; ++j){
            if(s[i] > s[j]){
                int tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }

    int av = (s[0]+s[1]+s[2]+s[3]+s[4])/5;

    cout << av << '\n' << s[2];

    return 0;
}
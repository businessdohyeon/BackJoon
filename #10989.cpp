/*
BaekJoon No
#10989
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    int result[10001] = {0};

    for(int i=0; i<n; ++i){
        int input;
        cin >> input;
        ++result[input];
    }

    for(int i=0; i<10001; ++i){
        if(result[i]==0)    continue;
        for(int j=0; j<result[i]; ++j)
            cout << i << '\n';
    }
    
    return 0;
}
/*
BaekJoon No
#17103
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    int inputMax = 1000000;
    bool is_NOT_Prime_Array[inputMax+1] = {0};
    is_NOT_Prime_Array[0] = true;
    is_NOT_Prime_Array[1] = true;
    for(int i=2; i<inputMax+1; ++i){
        if(is_NOT_Prime_Array[i]) continue;

        for(int j=2; i*j<inputMax+1; ++j)
            is_NOT_Prime_Array[i*j] = true;
    }


    int T;
    cin >> T;

    for(int i=0; i<T; ++i){
        int input;
        cin >> input;

        int cnt = 0;
        if(!is_NOT_Prime_Array[2] && !is_NOT_Prime_Array[input-2])
            ++cnt;
        for(int j=3; j<=input/2; j+=2)
            if(!is_NOT_Prime_Array[j] && !is_NOT_Prime_Array[input-j])
                ++cnt;

        cout << cnt << '\n';
    }

    return 0;
}
/*
BaekJoon No
#11659
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
    
    int size, cnt;
    cin >> size >> cnt;

    int input[size];
    int result[size+1];
    result[0] = 0;
    for(int i=0; i<size; ++i){
        cin >> input[i];
        result[i+1] = result[i]+input[i];
    }

    for(int i=0; i<cnt; ++i){
        int from, to;
        cin >> from >> to;
        cout << result[to]-result[from-1] << '\n';
    }

    return 0;
}
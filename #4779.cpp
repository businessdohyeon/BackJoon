/*
BaekJoon No
#4779
*/

#include <iostream>
#include <cmath>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void cantorianSet(char* arr, int size){
    if(size == 1)   return;
    
    cantorianSet(&arr[0], size/3);
    for(int i=size/3; i<2*size/3; ++i)
        arr[i] = ' ';
    cantorianSet(&arr[2*size/3], size/3);
}


int main(){
    setDefault();

    while(true){
        int n;
        cin >> n;

        if(cin.eof())   break;

        int size = pow(3, n);
        char arr[size];

        for(int i=0; i<size; ++i)
            arr[i] = '-';

        cantorianSet(arr, size);

        for(int i=0; i<size; ++i)
            cout << arr[i];
        cout << '\n';
    }

    return 0;
}
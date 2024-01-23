/*
BaekJoon No
#9063
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    unsigned int n;
    cin >> n;

    int x_min, x_max, y_min, y_max;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        if(i==0){
            x_min = x;
            x_max = x;

            y_min = y;
            y_max = y;
        }else{
            x_min = x < x_min ? x : x_min;
            x_max = x > x_max ? x : x_max;

            y_min = y < y_min ? y : y_min;
            y_max = y > y_max ? y : y_max;
        }
    }

    int w = x_max - x_min;
    int h = y_max - y_min;
    int area = w * h;

    cout << area;

    return 0;
}
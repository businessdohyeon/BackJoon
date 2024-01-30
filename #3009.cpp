/*
BaekJoon No
#3009
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;
    int x3, y3;
    cin >> x3 >> y3;

    int resultX, resultY;

    if(x1 != x2 && y1 != y2){       //1, 2
        resultX = x1+x2 - x3;
        resultY = y1+y2 - y3;
    }else if(x2 != x3 && y2 != y3){ //2, 3
        resultX = x2+x3 - x1;
        resultY = y2+y3 - y1;
    }else{                          //1, 3
        resultX = x1+x3 - x2;
        resultY = y1+y3 - y2;
    }

    cout << resultX << " " << resultY;

    return 0;
}
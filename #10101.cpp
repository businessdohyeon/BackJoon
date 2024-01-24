/*
BaekJoon No
#10101
*/

#include <iostream>
#include <string>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int ang1, ang2, ang3;
    cin >> ang1 >> ang2 >> ang3;

    string result;
    if(ang1+ang2+ang3 != 180)                               result = "Error";
    else if(ang1==60 && ang2==60 && ang3==60)               result = "Equilateral";
    else if(ang1 != ang2 && ang2 != ang3 && ang3 != ang1)   result = "Scalene";
    else                                                    result = "Isosceles";

    cout << result;

    return 0;
}
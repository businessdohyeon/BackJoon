/*
BaekJoon No
#1193
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

    int sumParentChild = 2;

    for(int i=1; n-i>0; ++i){
        n -= i;
        ++sumParentChild;
    }
    
    int child = sumParentChild%2 == 1 ? n : sumParentChild - n;
    int parent = sumParentChild - child;

    cout << child << "/" << parent;

    return 0;
}
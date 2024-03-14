/*
BaekJoon No
#1037
*/

#include <iostream>
#include <set>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    set<int> aliquots;
    for(int i=0; i<n; ++i){
        int input;
        cin >> input;
        aliquots.insert(input);
    }

    int firstElement = *aliquots.begin();
    int lastElement = *aliquots.rbegin();
    
    cout << firstElement * lastElement;

    return 0;
}
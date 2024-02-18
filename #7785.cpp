/*
BaekJoon No
#7785
*/

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    set<string, greater<string>> inCompany;
    for(int i=0; i<n; ++i){
        string name, status;
        cin >> name >> status;
        
        if(status == "enter")
            inCompany.insert(name);
        else
            inCompany.erase(inCompany.find(name));
    }

    for(auto p=inCompany.begin(); p!=inCompany.end(); ++p)
        cout << *p << '\n';

    return 0;
}
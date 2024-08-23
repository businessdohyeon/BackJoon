/*
BackJoon No.
#1264
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true){
        string str;
        getline(cin, str);

        if(str == "#")  break;

        int cnt = 0;
        for(auto itr = str.begin(); itr != str.end(); ++itr)
            if(*itr == 'a' || *itr == 'e' || *itr == 'i' || *itr == 'o' || *itr == 'u'
                    || *itr == 'A' || *itr == 'E' || *itr == 'I' || *itr == 'O' || *itr == 'U')
                ++cnt;

        cout << cnt << '\n';
    }

    return 0;
}
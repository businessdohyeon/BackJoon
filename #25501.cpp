/*
BaekJoon No
#25501
*/

#include <iostream>
#include <string>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool recursion(const string* p_str, int a, int b, int* p_cnt){
    ++(*p_cnt);

    if(a >= b)                          return 1;
    else if((*p_str)[a] != (*p_str)[b]) return 0;
    else                                return recursion(p_str, a+1, b-1, p_cnt);
}

bool isPalindrome(const string* p_str, int* p_cnt){
    return recursion(p_str, 0, p_str->length()-1, p_cnt);
}

int main(){
    setDefault();

    int n;
    cin >> n;

    for(int i=0; i<n; ++i){
        string input;
        cin >> input;

        int cnt = 0;
        bool result = isPalindrome(&input, &cnt);
        cout << result << ' ' << cnt << '\n';
    }

    return 0;
}
/*
BaekJoon No
#16139
*/

#include <iostream>
#include <string>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    string str;
    cin >> str;
    int n;
    cin >> n;

    int len = str.length();
    int prefixSum[len][26];
    // i 인덱스까지의 알파뱃 개수
    for(int i=0; i<len; ++i){
        int charOffset = str[i] - 'a';

        for(int j=0; j<26; ++j)
            if(j==charOffset)
                prefixSum[i][j] = i==0 ? 1 : prefixSum[i-1][j] +1;
            else
                prefixSum[i][j] = i==0 ? 0 : prefixSum[i-1][j];
    }

    for(int i=0; i<n; ++i){
        char ch;
        int from, to;
        cin >> ch >> from >> to;

        int charOffset = ch - 'a';
        int bigger = prefixSum[to][charOffset];
        int smaller = from==0 ? 0 : prefixSum[from-1][charOffset];
        cout << bigger - smaller << '\n';
    }

    return 0;
}
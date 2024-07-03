/*
BackJoon No.
#9592
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.size();
    int len2 = str2.size();

    int dp[len1+1][len2+1];
    for(int row=0; row<=len1; ++row)
        dp[row][0] = 0;
    for(int col=0; col<=len1; ++col)
        dp[0][col] = 0;

    for(int i=0; i<len1; ++i)
        for(int j=0; j<len2; ++j)
            if(str1[i] == str2[j])
                dp[i+1][j+1] = dp[i][j]+1;
            else
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);

    deque<char> lcs;
    for(int row=len1, col=len2; row>0 && col>0; ){
        if(str1[row-1] == str2[col-1]){
            lcs.push_front(str1[row-1]);
            --row;
            --col;
        }else if(dp[row-1][col] > dp[row][col-1]){
            --row;
        }else{
            --col;
        }
    }

    cout << lcs.size() << '\n';
    for(char e : lcs)
        cout << e;

    return 0;
}
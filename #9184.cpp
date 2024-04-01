/*
BaekJoon No
#9184
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    setDefault();

    int dp[21][21][21];

    for(int i=0; i<21; ++i)
        for(int j=0; j<21; ++j)
            dp[0][i][j] = 1;
    for(int i=0; i<21; ++i)
        for(int j=0; j<21; ++j)
            dp[i][0][j] = 1;
    for(int i=0; i<21; ++i)
        for(int j=0; j<21; ++j)
            dp[i][j][0] = 1;

    for(int a=1; a<21; ++a)
        for(int b=1; b<21; ++b) 
            for(int c=1; c<21; ++c)
                if(a<b && b<c)
                    dp[a][b][c] = dp[a][b][c-1] + dp[a][b-1][c-1] - dp[a][b-1][c];
                else
                    dp[a][b][c] = dp[a-1][b][c] + dp[a-1][b-1][c] + dp[a-1][b][c-1] - dp[a-1][b-1][c-1];

    while(true){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1)   break;

        int result;
        if(a<=0 || b<=0 || c<= 0)
            result = 1;
        else if(a>20 || b>20 || c>20)
            result = dp[20][20][20];
        else
            result = dp[a][b][c];

        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
    }
   
    return 0;
}
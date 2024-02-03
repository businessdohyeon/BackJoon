/*
BaekJoon No
#1018
*/

#include <iostream>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
}

int main(){
    setDefault();

    int n, m;
    cin >> n >> m;

    char s[n][m];
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin >> s[i][j];


    int result = -1;
    
    for(int i=0; i+7<n; ++i){
        for(int j=0; j+7<m; ++j){
            int black_first_case_cnt = 0;
            int white_first_case_cnt = 0;

            for(int a=0; a<8; ++a){
                for(int b=0; b<8; ++b){
                    char target = s[i+a][j+b];

                    if((a+b)%2 == 0){
                        if(target != 'B')   ++black_first_case_cnt;
                        else                ++white_first_case_cnt;
                    }else{
                        if(target != 'W')   ++black_first_case_cnt;
                        else                ++white_first_case_cnt;
                    }
                }
            }

            int min_cnt = black_first_case_cnt < white_first_case_cnt ? black_first_case_cnt : white_first_case_cnt;

            if(result == -1 || min_cnt < result)    result = min_cnt;
        }
    }

    cout << result;

    return 0;
}
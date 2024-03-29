/*
BaekJoon No
#14888
*/

#include <iostream>
#include <vector>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void process(int arr[], int n, int cnt[], vector<char>* p_operators, int* p_max, int* p_min, bool* p_isFirst){
    if(p_operators->size() >= n-1){
        int result = arr[0];
        for(int i=0; i<n-1; ++i){
            switch((*p_operators)[i]){
                case '+':
                    result += arr[i+1];
                    break;
                case '-':
                    result -= arr[i+1];
                    break;
                case '*':
                    result *= arr[i+1];
                    break;
                case '/':
                    result /= arr[i+1];
                    break;
                default:
                    break;
            }
        }

        if(*p_isFirst){
            *p_max = result;
            *p_min = result;
            *p_isFirst = false;
            return;
        }

        if(result > *p_max)     *p_max = result;
        if(result < *p_min)     *p_min = result;

        return;
    }

    for(int i=0; i<4; ++i){
        if(cnt[i] > 0){
            char tmp;
            switch(i){
                case 0:
                    tmp = '+';
                    break;
                case 1:
                    tmp = '-';
                    break;
                case 2:
                    tmp = '*';
                    break;
                case 3:
                    tmp = '/';
                    break;
                default:
                    break;
            }

            --cnt[i];
            p_operators->push_back(tmp);

            process(arr, n, cnt, p_operators, p_max, p_min, p_isFirst);

            ++cnt[i];
            p_operators->pop_back();
        }
    }
}

int main(){
    setDefault();

    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; ++i)
        cin >> arr[i];
        
    int cnt[4];
    for(int i=0; i<4; ++i)
        cin >> cnt[i];

    bool isFirst = true;
    int max, min;
    vector<char> operators;
    process(arr, n, cnt, &operators, &max, &min, &isFirst);

    cout << max << '\n' << min;

    return 0;
}
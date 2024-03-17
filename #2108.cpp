/*
BaekJoon No
#2108
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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

    vector<int> v;
    map<int, int> value_cnt_map;
    int sum = 0;
    for(int i=0; i <n; ++i){
        int input;
        cin >> input; 

        v.push_back(input);

        sum += input;

        if(value_cnt_map.find(input) == value_cnt_map.end())
            value_cnt_map[input] = 0;
        ++value_cnt_map[input];
    }


    sort(v.begin(), v.end());


    double weight = sum > 0 ? 0.5 : -0.5;
    int av = (double)sum / n + weight;

    int center = v[n/2];

    int mode;
    int max_cnt = 0;
    bool isSecond = true;
    for(auto pair : value_cnt_map){
        if(pair.second > max_cnt){
            mode = pair.first;
            max_cnt = pair.second;
            isSecond = true;
        }else if(pair.second == max_cnt && isSecond){
            mode = pair.first;
            isSecond = false;
        }
    }

    int range = v.back() - v.front();




    cout << av << '\n';
    cout << center << '\n';
    cout << mode << '\n';
    cout << range << '\n';

    return 0;
}
/*
BaekJoon No
#24060
*/

#include <iostream>
#include <vector>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void merge(int arr[], int start, int mid, int end, int* p_cnt, int* p_result, int k){
    vector<int> tmp;

    for(int i=start, j=mid+1; i<=mid || j<=end; ){
        if(i == mid+1){
            tmp.push_back(arr[j]);
            ++j;
        }else if(j == end+1){
            tmp.push_back(arr[i]);
            ++i;
        }else{
            if(arr[i] <= arr[j]){
                tmp.push_back(arr[i]);
                ++i;
            }else{
                tmp.push_back(arr[j]);
                ++j;
            }
        }
    }

    for(int i=start; i<=end; ++i){
        arr[i] = tmp[i-start];

        ++(*p_cnt);
        if(*p_cnt == k) 
            *p_result = arr[i];
    }
};

void merge_sort(int arr[], int start, int end, int* p_cnt, int* p_result, int k){
    if(start >= end)    return;

    int mid = (start+end)/2;
    merge_sort(arr, start, mid, p_cnt, p_result, k);
    merge_sort(arr, mid+1, end, p_cnt, p_result, k);

    merge(arr, start, mid, end, p_cnt, p_result, k);
}


int main(){
    setDefault();

    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    
    int cnt = 0, result = -1;
    merge_sort(arr, 0, n-1, &cnt, &result, k);
    
    cout << result;

    return 0;
}
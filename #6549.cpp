/*
BaekJoon No
#6549
*/

#include <iostream>
#include <algorithm>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

long long maxArea(int input[], int startIdx, int size){
    if(size == 1)   return input[startIdx];

    int rightIdxOfBorder = startIdx + size/2;
    int leftIdxOfBorder = rightIdxOfBorder-1;

    long long height = min(input[leftIdxOfBorder], input[rightIdxOfBorder]);
    long long width = 2;
    long long area = height*width;

    int left = leftIdxOfBorder-1;
    int right = rightIdxOfBorder+1;
    while(left >= startIdx && right < startIdx + size){
        if(input[left] > input[right]){
            height = min(height, (long long)input[left]);
            ++width;
            long long newArea = height*width;
            if(newArea > area)
                area = newArea;
            --left;
        }else{
            height = min(height, (long long)input[right]);
            ++width;
            long long newArea = height*width;
            if(newArea > area)
                area = newArea;
            ++right;
        }
    }
    while(left >= startIdx){
        height = min(height, (long long)input[left]);
        ++width;
        long long newArea = height*width;
        if(newArea > area)
            area = newArea;
        --left;
    }
    while(right < startIdx + size){
        height = min(height, (long long)input[right]);
        ++width;
        long long newArea = height*width;
        if(newArea > area)
            area = newArea;
        ++right;
    }

    long long bigger;
    if(size%2 == 0)
        bigger = max(maxArea(input, startIdx, size/2), maxArea(input, rightIdxOfBorder, size/2));
    else
        bigger = max(maxArea(input, startIdx, size/2), maxArea(input, rightIdxOfBorder, size/2+1));

    return max(area, bigger);
}

int main(){
    setDefault();

    while(true){
        int n;
        cin >> n;

        if(n==0)    break;

        int input[n];
        for(int i=0; i<n; ++i)
            cin >> input[i];

        cout << maxArea(input, 0, n) << '\n';
    }

    return 0;
}
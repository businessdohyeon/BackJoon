/*
BackJoon No.
#1725
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long s[n];
    for(int i=0; i<n; ++i)
        cin >> s[i];

    long long max = 0;
    vector<long long> stack;
    for(int i=0; i<n; ++i){
        while(!stack.empty() && s[stack.back()] > s[i]){
            long long height = s[stack.back()];
            stack.pop_back();
            long long width = stack.empty() ? i : i - stack.back() -1;
            long long area = height * width;
            if(area > max)  max = area;
        }
        stack.push_back(i);
    }
    
    while(!stack.empty()){
        long long height = s[stack.back()];
        stack.pop_back();
        long long width = stack.empty() ? n : n - stack.back() -1;
        long long area = height * width;
        if(area > max)  max = area;
    }

    cout << max;

    return 0;
}
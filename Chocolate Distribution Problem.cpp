#include<iostream>
#include<vector>
#include <bits/stdc++.h>

class Solution{
private:
public:
    long long findMinDiff(std::vector<long long> a, long long n, long long m){
        //code
        std::sort(a.begin(), a.end());
        long long diff=INT_MAX;
        for (int i = 0; i < n-m+1; i++){
            std::cout << a[i] << " ";
            diff=std::min(diff,a[i+m-1]-a[i]);
        }
        return diff;
    }
};

int main(){
    std::vector<long long> arr={3, 4, 1, 9, 56, 7, 9, 12};
    long long m=5;
    Solution solution;
    solution.findMinDiff(arr, (long long)arr.size(), m);
}
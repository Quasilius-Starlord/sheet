#include <iostream>
#include <bits/stdc++.h>

class Solution{
private:
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        if(n==1)
            return 0;
        int window=0;
        int i=0,j=0;
        int validity=0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]<=k)
                window++;
        }
        
        for (j = 0; j < window; j++)
        {
            if(arr[j]<=k){
                validity++;
            }
        }
        int num=INT_MAX;
        num=std::min(num, window-validity);
        for (i = 1; i < n-window+1; i++)
        {
            if(arr[i-1]<=k)
                validity--;
            if(arr[i+window]<=k)
                validity++;
            num=std::min(num, window-validity);
        }
        // std::cout << num;
        return num;
    };
};

int main(){
    int arr[]={2, 7, 9, 5, 8, 7, 4};
    int n=7,k=6;
    Solution solution;
    solution.minSwap(arr, n, k);
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

// bool comparator

long long int absolute(long long int a){
    return a>0 ? a : (a*-1);
}

class Solution{
private:
public:
    int merge(long long int arr[], long long int temp[], int left, int mid, int right){
        int i=left, j=mid+1;
        int k=0;
        int count=0;
        while (i<=mid && j<=right)
        {
            if(arr[i]>arr[j]){
                temp[k]=arr[j];
                count+=mid-i+1;
                j++;
            }else{
                temp[k]=arr[i];
                i++;
            }
            k++;
        }
        while (i<=mid)
        {
            temp[k]=arr[i];
            i++;k++;
        }
        while (j<=right)
        {
            temp[k]=arr[j];
            j++;k++;
        }
        i=left;
        k=0;
        while (i<=right)
        {
            arr[i]=temp[k];
            i++;
            k++;
        }
        return count;
    };
    int mergesort(long long int arr[], long long int temp[], int left, int right){
        if(left>=right)
            return 0;
        int mid=(right+left)/2;
        int count = 0;
        count+=this->mergesort(arr, temp, left, mid);
        count+=this->mergesort(arr, temp, mid+1, right);
        count+=this->merge(arr, temp, left, mid, right);
        return count;
    };

    int inversionCount(long long int arr[], int N){
        long long int count=0;
        long long int temp[N];
        count=this->mergesort(arr, temp, 0, N-1);
        return count;
    }
};

int main(){
    Solution solution;
    long long int arr[]={2, 4, 1, 3, 5};
    long long int n=5;
    std::cout << solution.inversionCount(arr, n) << "\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << "\n";
    }
    
}
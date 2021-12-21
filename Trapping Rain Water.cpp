#include <iostream>
#include<bits/stdc++.h>

class Solution{
    long long max(long long a, long long b){
        return a>b? a : b;
    };
    long long min(long long a, long long b){
        return a<b? a : b;
    };
private:
public:
    int collected(int arr[], int n){
        int leftgreatest[n];
        int rightgreatest[n];
        int temp=INT_MIN;
        leftgreatest[0]=arr[0];
        rightgreatest[n-1]=arr[n-1];
        for (int i = 1; i < n; i++){
            leftgreatest[i]=std::max(arr[i],leftgreatest[i-1]);
            rightgreatest[n-1-i]=std::max(arr[n-1-i],rightgreatest[n-i]);
        }
        int water=0;
        for (int i = 0; i < n; i++){
            water+=std::min(leftgreatest[i],rightgreatest[i])-arr[i];
        }
        return water;
    }
};

int main(){
    int arr[]={3,0,0,8,7};
    Solution solution;
    solution.collected(arr,5);
}
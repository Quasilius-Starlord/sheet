#include<iostream>
#include<bits/stdc++.h>

class Solution{
private:
    bool twopointer(int arr[], int size, int num){
        int start=0,end=size-1;
        int sum;
        while (start<end)
        {
            sum=arr[start]+arr[end];
            if(sum>num)
                start++;
            else if(sum<num)
                end--;
            else
                return true;
        }
        return false;
    }
public:
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        if(n<=2)
            return false;
        std::sort(A, A+n, std::greater<int>());
        for (int i = 0; i < n; i++)
            std::cout << A[i] << " ";
        std::cout << "\n";
        int remaining;
        for (int i = 0; i < n-2; i++)
        {
            if(A[i]>=X)
                continue;
            remaining=X-A[i];
            if(this->twopointer(A+i+1,n-i-1,remaining))
                return true;
        }    
        return false;
    }
};

int main(){
    Solution solution;
    int arr[]={1,4,45,6,10,8};
    int n=6,x=10;
    std::cout << solution.find3Numbers(arr,n,x);
}
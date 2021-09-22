#include <iostream>

class Solution{
private:
    int *dp;
    int getmax(int arr[], int n){
        if(n==0)
            return -1;
        int ans=arr[0];
        for (int i = 0; i < n; i++)
            ans=arr[i] > ans ? arr[i] : ans;
        return ans;
        
    };
    int helper(int arr[], int n, int i){
        if(i>=n)
            return 0;
        if(this->dp[i]!=-1)
            return dp[i];
        
        int ans=arr[i];
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]>arr[i])
                ans=std::max(ans,arr[i]+this->helper(arr,n,j));
        }
        this->dp[i]=ans;
        return ans;
    };
public:
    int maxSumIS(int arr[], int n)  
	{
        this->dp=new int[n];
        for (int i = 0; i < n; i++)
            this->dp[i]=-1;
        
        for (int i = 0; i < n; i++)
            this->helper(arr,n,i);

        // for (int i = 0; i < n; i++)
        // {
        //     std::cout << dp[i] << " ";
        // }
        
        return this->getmax(dp,n);
	    // Your code goes here
	};

    Solution(){
        this->dp=nullptr;
    }
};

int main(){
    Solution solution;
    int n=8;
    int arr[n]={44, 42, 38, 21, 15, 22, 13, 27};
    std::cout << solution.maxSumIS(arr,n);

}
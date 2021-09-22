#include <iostream>

class Solution{
private:
    int *dp;
    int helper(int A[], int N, int i){
        if(i>=N)
            return 0;
        if(this->dp[i]!=-1)
            return dp[i];
        
        int ans=1;
        for (int j = i+1; j < N; j++)
        {
            if(std::abs(A[i]-A[j])==1)
                ans=std::max(ans,1+this->helper(A,N,j));
        }
        this->dp[i]=ans;
        return ans;
        
    };
    int getmax(int arr[], int n){
        if(n==0)
            return -1;
        int ans=arr[0];
        for (int i = 0; i < n; i++)
            ans=arr[i] > ans ? arr[i] : ans;
        return ans;
        
    };
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        this->dp=new int[N];

        for (int i = 0; i < N; i++)
            this->dp[i]=-1;
        
        for (int i = 0; i < N; i++)
            this->helper(A,N,i);

        return this->getmax(this->dp,N);
    }
};

int main(){
    Solution solution;
    int n=7;
    int a[n]={9,10,4,5,4,8,6};
    std::cout << solution.longestSubsequence(n,a);
}
#include <iostream>

class Solution{
private:
    int* dp;
    int helper(int a[], int i, int fix, int n){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        for (int j = i+1; j < n; j++)
        {
            if(a[j]>a[i])
                ans=std::max(ans,1+this->helper(a,j,fix,n));
        }
        dp[i]=ans;
        return ans;
    };
public:
    int longestSubsequence(int n, int a[])
    {
        // your code here
        dp=new int[n];
        for (int i = 0; i < n; i++)
            dp[i]=-1;
        
        int ans=0;
        for (int i = 0; i < n; i++)
        {
            ans=std::max(ans,1+this->helper(a,i,0,n));
        }

        for (int i = 0; i < n; i++)
            std::cout << a[i] << " " << dp[i] << "\n";
        return ans;
    };

    Solution(){
        this->dp=nullptr;
    }
};

int main(){
    Solution solution;
    int n=6;
    int a[n]={5,8,3,7,9,1};
    std::cout << solution.longestSubsequence(n,a);
}
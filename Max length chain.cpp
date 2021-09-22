#include <iostream>
#include <algorithm>
/*
The structure to use is as follows
*/
struct val{
	int first;
	int second;
    val(int a, int b){
        this->first=a;
        this->second=b;
    }
};

class Solution{
private:
    int print(struct val p[], int n){
        for (int i = 0; i < n; i++)
            std::cout << p[i].first << " " << p[i].second << "\n";
        return n;
    };

    int maxarr(int arr[], int n){
        if(n<0)
            return -1;
        
        int ans=arr[0];
        for (int i = 0; i < n; i++)
            ans=arr[i]>ans ? arr[i] : ans;
        return ans;
    };

    int helper(struct val p[], int dp[], int i, int n){
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=1;
        for (int j = i+1; j < n; j++)
        {
            if(p[i].second < p[j].first)
                ans=std::max(ans, 1+this->helper(p, dp, j, n));
        }
        dp[i]=ans;
        return ans;
    }

public:
    int maxChainLen(struct val p[],int n)
    {
        //Your code here
        std::sort(p,p+n,[](const val& left,const val& right){
            return left.first < right.first;
        });
        int dp[n];
        for (int i = 0; i < n; i++)
            dp[i]=-1;
        for (int i = 0; i < n; i++)
            helper(p, dp, i, n);

        // this->print(p,n);
        return this->maxarr(dp,n);
    }
};

int main(){
    int N=5;
    struct val p[]{{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    Solution solution;
    std::cout << solution.maxChainLen(p,N);;
}
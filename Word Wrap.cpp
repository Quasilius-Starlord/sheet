#include<iostream>
#include<vector>

class Solution {
    int helper(std::vector<int>& nums,int* dp, int i, int k){
        if(i>=nums.size())
            return 0;
        // if(dp[i]!=-1)
        //     return dp[i];
        // int empty=k-nums[i];
        // int cost=0;

        int cost=INT_MAX;
        int empty=k+1;
        int j;
        for (j = i; j < nums.size(); j++)
        {
            empty=empty-1-nums[j];
            if(empty<0)
                break;
            cost=std::min(cost,(empty*empty)+this->helper(nums,dp,j+1,k));
        }
        if(j==nums.size())
            cost=0;
        // while (empty>=0)
        // {
        //     cost+=empty*empty;
        //     cost=std::min(cost,cost+this->helper(nums,i+1,k));
        //     i++;
        //     if(i>=nums.size())
        //         break;
        //     empty=empty-1-nums[i];
        // }
        dp[i]=cost;
        return cost;
    };
public:
    int solveWordWrap(std::vector<int>nums, int k) 
    {
        // Code here
        // int cost=nums[0];
        int dp[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            dp[i]=-1;
        this->helper(nums,dp,0,k);
        for (int i = 0; i < nums.size(); i++)
            std::cout << dp[i] << " ";
        std::cout << "\n";
        return dp[0];
    }
};

int main(){
    Solution solution;
    std::vector<int> nums={9,3,10,6,9,9,7};
    int k=12;
    // std::vector<int> nums={3,2,2,5};
    // int k=6;
    // std::vector<int> nums={1,1,1,1,2};
    // int k=4;
    std::cout << solution.solveWordWrap(nums,k);
}
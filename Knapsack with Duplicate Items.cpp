#include <iostream>

class Solution{
private:
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[W+1];
        std::fill_n(dp,W+1,0);
        int cost=0;
        int unit;
        for (int i = 1; i < W+1; i++)
        {
            int cost=-1;
            for (int j = 0; j < N; j++)
            {
                if(wt[j]>i)
                    continue;
                // unit=i/wt[j];
                cost=std::max(cost, val[j] + dp[i-wt[j]]);
            }
            dp[i]=cost;
        }
        // for (int i = 0; i < W+1; i++)
        // {
        //     std::cout << dp[i] << " ";
        // }
        
        return dp[W];
    }
};

int main(){
    Solution solution;
    int val[]={}
}
#include <iostream>

class Solution{
private:
public:
    long long int countBT(int h) {
        // code here
        long long int dp[h];
        std::fill_n(dp,h,1);

        if(h==1)
            return 1;
        
        if(h==2)
            return 3;
        
        dp[0]=1;
        dp[1]=3;
        long long int c=0;
        // int M=
        int M=1e9;
        M+=7;

        for (int i = 2; i < h; i++)
        {
            dp[i]=(dp[i]*dp[i-1])%M;
            dp[i]=(dp[i]*dp[i-2])%M;
            dp[i]=(dp[i]*2)%M;
            c=(dp[i-1]*dp[i-1])%M;
            dp[i]=(dp[i]+c)%M;
            // std::cout << dp[i] << " ";
        }
        return dp[h-1];
    }
};

int main(){
    int M=1e9;
    M+=7;
    // std::cout << M;
    Solution solution;
    solution.countBT(4);
} 
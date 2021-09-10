#include <iostream>

class Solution{
private:
    
public:
    int nCr(int n, int r){
        if(r>n)
            return 0;
        
        int dp[r][n];
        long long int place=0;
        
        for (int i = 0; i < n; i++)
            dp[0][i]=i+1;
        
        long long int M=1e9;
        M+=7;
        //std::cout << M << "\n";

        for (int i = 1; i < r; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //j for col i for row
                //j is n and i is r
                if(i>j){
                    dp[i][j]=0;
                    continue;
                }else if(i==j)
                {
                    dp[i][j]=1;
                    continue;
                }
                place=(dp[i-1][j-1]+dp[i][j-1]) % M;
                // std::cout << place << " ";
                dp[i][j]=place;
            }
            // std::cout << "\n";
        }
        // for (int i = 0; i < r; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         std::cout << dp[i][j] << " ";
        //     }
        //     std::cout << "\n";
        // }
        
        return dp[r-1][n-1];
    }
};

int main(){
    Solution solution;
    std::cout << solution.nCr(778,116);
}
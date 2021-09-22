#include <iostream>
#include <vector>

class Solution{
private:
public:
    int maxGold(int n, int m, std::vector<std::vector<int>> M)
    {
        // code here
        int dp[n][m];
        dp[0][0]=M[0][0];
        for (int i = 1; i < m; i++)
            dp[0][i]=dp[0][i-1]+M[0][i];
        
        for (int i = 1; i < n; i++)
            dp[i][0]=std::max(dp[i-1][0],M[i][0]);

        int sum=0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                sum=std::max(M[i][j],M[i-1][j]);
                dp[i][j]=std::max(dp[i][j-1]+sum,dp[i-1][j]);
            }
        }
        
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         std::cout << dp[i][j] << " ";
        //     }
        //         std::cout << "\n";
        // }
        return dp[n-1][m-1];
    }

    //n rows m columns
    int maxgold(int n, int m, std::vector<std::vector<int>> M){
        if(M.size()==1){
            int acc=0;
            for (int i = 0; i < M[0].size(); i++)
            {
                acc+=M[0][i];
            }
            return acc;
        }
        for (int j = m-2; j >= 0; j--)
        {
            M[0][j]+=std::max(M[0][j+1],M[1][j+1]);
            for (int i = 1; i < n-1; i++)
            {
                M[i][j]+=std::max(M[i][j+1],std::max(M[i-1][j+1],M[i+1][j+1]));
            }
            M[n-1][j]+=std::max(M[n-1][j+1],M[n-2][j+1]);
        }
        int acc=0;
        for (int i = 0; i < M.size(); i++)
            acc=std::max(acc,M[i][0]);
        return acc;
    }
};

//n is the row m is the column
int main(){
    Solution solution;
    int m=4,n=4;
    // int M[][100]={{10, 33, 13, 15},
    //               {22, 21, 04, 1},
    //               {5, 0, 2, 3},
    //               {0, 6, 14, 2}};
    std::vector<std::vector<int>> M={{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
    std::cout << solution.maxgold(M.size(),M[0].size(),M);
}
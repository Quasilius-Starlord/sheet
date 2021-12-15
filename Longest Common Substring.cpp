#include <iostream>
#include <string>

class Solution{
private:
public:
    // n is for s1 and m is for s2
    int longestCommonSubstr (std::string S1, std::string S2, int n, int m)
    {
        // your code here
        n=S1.size();
        m=S2.size();

        int dp[n+1][m+1];

        for (int i = 0; i < n+1; i++)
            dp[i][0]=0;
        for (int i = 0; i < m+1; i++)
            dp[0][i]=0;
        
        for (int i = 1; i < n+1; i++)
        {
            for (int j = 1; j < m+1; j++)
            {
                std::cout << S1[i-1] << " " << S2[j-1] << "\n";
                if(S1[i-1]==S2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0;
            }
            // std::cout << "\n";
        }

        int acc=0;
        for (int i = 0; i < n+1; i++)
        {
            for (int j = 0; j < m+1; j++)
            {
                std::cout << dp[i][j] << " ";
                acc=dp[i][j] > acc ? dp[i][j] : acc;
            }
            std::cout << "\n";
        }
        return acc;
    }
};

int main(){
    Solution solution;
    solution.longestCommonSubstr("ABC", "AC",0,0);
}
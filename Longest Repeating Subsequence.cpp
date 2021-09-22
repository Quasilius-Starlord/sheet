#include <iostream>
#include <string>
#include <cstring>

class Solution{
private:
public:
    int LongestRepeatingSubsequence(std::string str){
        int x=str.size();

        int dp[x+1][x+1];

        for (int i = 0; i < x+1; i++){
            dp[0][i]=0;
            dp[i][0]=0;
        }

        for (int i = 1; i < x+1; i++)
        {
            for (int j = 1; j < x+1; j++)
            {
                if(i==j){
                    dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
                    continue;
                }
                if(str[i-1]==str[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
            }
        }

        for (int i = 0; i < x+1; i++)
        {
            for (int j = 0; j < x+1; j++)
            {
                std::cout << dp[i][j] << " ";
            }
            std::cout << "\n";
        }
        
        return dp[x][x];
        
    }
};

int main(){
    Solution solution;
    std::cout << solution.LongestRepeatingSubsequence("axxxy");
}
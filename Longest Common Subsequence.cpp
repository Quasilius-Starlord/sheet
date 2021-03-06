#include <iostream>
#include <string>

class Solution
{
    public:
    int lcs(int x, int y, std::string s1, std::string s2)
    {
        // your code here
        x=s1.size();
        y=s2.size();

        
        //x+1 rows y+1 column
        int dp[x+1][y+1];
        for (int i = 0; i < x+1; i++){
            for (int j = 0; j < y+1; j++)
                dp[i][j]=-1;
        }
        
        for (int i = 0; i < x+1; i++)
            dp[i][0]=0;
        
        for (int i = 0; i < y+1; i++)
            dp[0][i]=0;
        
        for (int i = 1; i < x+1; i++)
        {
            for (int j = 1; j < y+1; j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
};

int main(){
    Solution soluton;
}
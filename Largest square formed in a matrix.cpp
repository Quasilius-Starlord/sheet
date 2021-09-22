#include <iostream>
#include <vector>

class Solution{
private:
    int getvalue(int i, int j, std::vector<std::vector<int>>& mat){
        if(i<0 || j<0)
            return 0;
        else if(i>=mat.size())
            return 0;
        else if(j>=mat[0].size())
            return 0;
        else
            return mat[i][j];
    }
public:
    int maxSquare(int n, int m, std::vector<std::vector<int>> mat){
        std::vector<std::vector<int>> dp{ (std::vector<std::vector<int>>::size_type)n, std::vector<int>(m)};
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                dp[i][j]=0;
        }

        for (int i = 0; i < n; i++){
            dp[i][0]=mat[i][0];
        }

        for (int i = 0; i < m; i++){
            dp[0][i]=mat[0][i];
        }
        
        int ans=0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if(mat[i][j]==0)
                    dp[i][j]=0;
                else{
                    dp[i][j]=std::min(std::min(this->getvalue(i-1,j,dp) ,this->getvalue(i,j-1,dp)),this->getvalue(i-1,j-1,dp))+1;
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans=dp[i][j] > ans ? dp[i][j] : ans;
                std::cout << mat[i][j] << " ";
            }
                std::cout << "\n";
        }
        return ans;
    };
};

//n rows i and m column j
int main(){
    Solution solution;
    int n=5 , m=6;
    std::vector<std::vector<int>> mat={{0,1, 0, 1, 0, 1},{1, 0, 1, 0, 1, 0},{0, 1, 1, 1, 1, 0},{0, 0, 1, 1, 1, 0},{1, 1, 1, 1, 1, 1}};
    std::cout << solution.maxSquare(n,m,mat);
}
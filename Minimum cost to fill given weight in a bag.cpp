#include <iostream>

class Solution{
private:
public:
    int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        int dp[W+1][N];
        dp[0][0]=0;
        //W is row N is column
        int c;
        for (int i = 0; i < N; i++)
            dp[0][i]=0;
        
        for (int i = 1; i < W+1; i++){
            if(cost[0]==-1)
                dp[i][0]=INT_MAX;
            else{
                dp[i][0]=cost[0]*i;
            }
        }
        int q;
        for (int i = 1; i < W+1; i++)
        {
            for (int j = 1; j < N; j++)
            {
                if(j+1>i){
                    dp[i][j]=dp[i][j-1];
                    continue;
                };

                if(cost[j]==-1){
                    dp[i][j]=dp[i][j-1];
                    continue;
                }
                if(dp[i-j-1][j]==INT_MAX){
                    dp[i][j]=std::min(INT_MAX,dp[i][j-1]);
                    continue;
                }
                q=cost[j];
                q+=dp[i-j-1][j];
                dp[i][j]=std::min(q,dp[i][j-1]);
            }
        }
        for (int i = 0; i < W+1; i++)
        {
                std::cout << i << " ";
            for (int j = 0; j < N; j++)
            {
                std::cout << dp[i][j] << " ";
            }
            std::cout << "\n";
        }
        if(dp[W][N-1]==INT_MAX)
            return -1;
        else
            return dp[W][N-1];
	}
};

int main(){
    Solution solution;
    int arr[]={-1, 25, 78, 40, 77, 66, 13, 96, 76, 92, 11, 67, 11, 94};
    int w=29,n=14;
    solution.minimumCost(arr,n,w);
}
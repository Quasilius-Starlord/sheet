#include <iostream>
#include <bits/stdc++.h>

class Solution{
private:
public:
    long long int count(int S[], int m, int n){
        std::sort(S,S+m);
        int dp[m][n+1];
        for (int i = 0; i < n+1; i++)
        {
            if( i % S[0] == 0 )
                dp[0][i]=1;
            else
                dp[0][i]=0;
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n+1; j++)
            {
                if(S[i]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-S[i]];
            }
        }
        // std::cout << "answer " << dp[m-1][n];
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n+1; j++)
        //     {
        //         std::cout << dp[i][j] << " ";
        //     }
        //     std::cout << "\n";
        // }
        
        return dp[m-1][n];
    }
};

//m size of array n is the sum
int main(){
    // int m=3,n=5;
    // int S[]={1,2,3};
    int m=8,n=7;
    int S[]={1,2,3,4,7,8,9,11};
    Solution solution;
    solution.count(S,m,n);
}
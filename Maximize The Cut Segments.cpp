#include <iostream>
#include <bits/stdc++.h>

class Solution{
private:
public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int dp[n+1];
        int arr[3];
        arr[0]=x;
        arr[1]=y;
        arr[2]=z;
        std::sort(arr,arr+3);
        dp[0]=0;
        int sum=-1;
        for (int i = 1; i < n+1; i++)
        {
            dp[i]=0;
            sum=-1;
            for (int j = 0; j < 3; j++)
            {
                if(i-arr[j] < 0){
                    continue;
                }else if(dp[i-arr[j]] < 0){
                    continue;
                }else{
                    sum=std::max(sum, dp[i-arr[j]]+1);
                }
            }
            dp[i]=sum;
        }
        // for (int i = 0; i < n+1; i++)
        //     std::cout << dp[i] << " ";
        // std::cout << "\n";
        if(dp[n]==-1)
            return 0;
        return dp[n];
    }
};

int main(){
    Solution solution;
    std::cout << solution.maximizeTheCuts(7,5,2,2);
}
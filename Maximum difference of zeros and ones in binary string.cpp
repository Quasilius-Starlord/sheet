#include <iostream>
#include <string>

class Solution{
private:

public:
    int maxSubstring(std::string S)
	{
	    // Your code goes here
        int dp[(int)S.size()];
        bool flag=false;
        if(S[0]=='0')
            dp[0]=1;
        else
            dp[0]=-1;
        for (int i = 1; i < S.size(); i++)
        {
            if(S[i]=='0'){
                if(dp[i-1]<=0)
                    dp[i]=1;
                else
                    dp[i]=dp[i-1]+1;
            }else{
                    dp[i]=dp[i-1]-1;
                // if(dp[i-1]<=0)
                // else
                //     dp[i]=dp[i-1]+1;
                // dp[i]=dp[i-1]-1;
            }
        }
        int acc=-1;
        for (int i = 0; i < S.size(); i++){
            std::cout << dp[i] << " ";
            // if(dp[i] <= acc)
            //     continue;
            acc=dp[i] > acc ? dp[i] : acc;
        }
        return acc;
	}
};

int main(){
    std::string str="11000010001";
    Solution solution;
    solution.maxSubstring(str);
}
#include <iostream>
#include <string>

class Solution{
private:
    int ispalindrome(std::string& s , int** dp, int start, int end){
        if(start==end)
            return 0;
        if(start>end)
            return 0;
        if(dp[start][end]!=-1){
            if(dp[start][end]==0)
                return 0;
            else
                return 1;
            // return dp[start][end];
        }
        if(s[start]==s[end]){
            int state=false || (bool)this->ispalindrome(s,dp,start+1,end-1);
            // dp[start][end]=state;
            // if(dp[start][end])
            return state;
        }else{
            // dp[start][end]=0;
        // std::cout << "jher";
            return 1;
        }
    };

    int helper(std::string& s, int** dp, int start, int end){
        if(start>end)
            return 0;
        if(start==end)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        if(this->ispalindrome(s,dp,start,end)==0){
            dp[start][end]=0;
            return 0;
        }
        // std::cout << "for wing " << start << "\n";
        int part=end-start;
        int sum=end-start;
        for (int i = start; i < end; i++)
        {
            // std::cout << i << " " << end << " " << wing << " " << this->helper(s,dp,start,i,wing+1) << "\n";
            
            sum=std::min(sum,this->helper(s,dp,start,i)+1+this->helper(s,dp,i+1,end));
        }
        dp[start][end]=sum;
        return sum;
    }
public:
    int palindromicPartition(std::string s){
        int n=s.size();
        if(n==1)
            return 0;

        int** dp=new int*[n];
        for (int i = 0; i < n; i++)
            dp[i]=new int[n];
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dp[i][j]=-1;
            }    
        }
        if(this->ispalindrome(s,dp,0,n-1)==0)
            return 0;

        return this->helper(s,dp,0,n-1);
    }
};

int main(){
    Solution solution;
    std::cout << solution.palindromicPartition("ababbbabbababa");
}
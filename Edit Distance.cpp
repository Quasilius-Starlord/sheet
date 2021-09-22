#include <iostream>
#include <string>

class Solution{
private:
public:
    int minthie(int a, int b, int c){
        return std::min(a,std::min(b,c));
    };
    int editDistance(std::string s, std::string t) {
        int columnsize=s.size()+1;
        int rowsize=t.size()+1;
        //column source row is destination
        int dp[rowsize][columnsize];

        for (int i = 0; i < columnsize; i++)
            dp[0][i]=i;
        
        for (int i = 0; i < rowsize; i++)
            dp[i][0]=i;
        
        // i row is for t and j column is for s
        for (int i = 1; i < rowsize; i++)
        {
            for (int j = 1; j < columnsize; j++)
            {
                if(s[j-1]==t[i-1]){
                    dp[i][j]=dp[i-1][j-1];
                    continue;
                }else{
                    dp[i][j]=1+this->minthie(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
                }
            }
        }
        return dp[rowsize-1][columnsize-1];
    }
};

int main(){

}
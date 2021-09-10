#include <iostream>
#include <bits/stdc++.h>
#include <string>

class Solution{
private:
    int** dp;
    long long int helper(int S[], int m, int n, int mask,std::string str){
        if(n==0){
                std::cout << "mask " << mask << " " << str << "\n";
            if(this->exist[mask]!=1){
                this->exist[mask]=1;
                return 1;
            }
        }
        if(n<=0)
            return 0;
        long long int ans=0;
        for (int i = 0; i < m; i++)
        {
            if(S[i]>n)
                break;
            ans+=this->helper(S, m, n-S[i], mask | (1<<i), str+", "+ std::to_string(S[i]));
        }
        return ans;
    }
public:
    long long int count( int S[], int m, int n )
    {
        dp=new int*[m];
        // int sii=1<<m;
        for (int i = 0; i < m; i++){
            dp[i]=new int[n+1];
            for (int j = 0; j < n+1; j++)
                dp[i][j]=-1;
        }

        
        std::sort(S,S+m);
        long long int ans=this->helper(S,m,n,0,"");
        std::cout << "answer " << ans;
        return ans;
    }
    Solution(){
        this->exist=nullptr;
    }
};
//m size of array n is the sum
int main(){
    // int m=8,n=7;
    // int S[]={1,2,3,4,7,8,9,11};
        int m=3,n=5;
    int S[]={1,2,3};
    // int m=4,n=10;
    // int S[]={2,5,3,6};
    Solution solution;
    solution.count(S, m, n);
}
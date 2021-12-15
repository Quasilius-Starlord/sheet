#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution{
private:
    std::unordered_set<std::string> map;
    int *dp;
    bool helper(std::string A, int i){
        if(i>=A.size())
            return (bool)1;
        if(dp[i]!=-1)
            return dp[i];

        bool test=false;
        for (int j = i+1; j <= A.size(); j++)
        {
            test=test || (( this->map.find(A.substr(i,j-i))!=this->map.end() ) && this->helper(A, j));
        }
        return dp[i]=test;
    };
public:
    int wordBreak(std::string A, std::vector<std::string> &B) {
        //code here
        int n=A.size();
        bool dp[n+1];
        std::fill_n(dp,n+1,false);

        std::unordered_set<std::string> map;

        for (int i = 0; i < B.size(); i++)
            map.insert(B[i]);
        int back=0;
        
        dp[0]=true;
        for (int i = 1; i < n+1; i++)
        {
            std::cout << A.substr(back,i-back) << " " << "\n"; 
            if(map.find(A.substr(back,i-back))==map.end()){
                //not found
                std::cout << "not found\n";
                dp[i]=false;
            }else{
                //found
                std::cout << "found\n";
                dp[i]=true && dp[back];
                back=i;
            }
        }
        // std::unordered_set<std::string>::iterator i;
        // for (i = map.begin(); i != map.end(); i++)
        // {
        //     std::cout << *i << " ";
        // }
        for (int i = 0; i < n+1; i++)
        {
            std::cout << dp[i] << " ";
        }
        return 0;
    };

    int wordBreak2(std::string A, std::vector<std::string> &B){
        for (int i = 0; i < B.size(); i++)
            this->map.insert(B[i]);
        dp=new int[A.size()+1];
        std::fill_n(this->dp,A.size()+1,-1);
        std::cout << this->helper(A,0);
        return 0;
    }
};

int main(){
    // std::string A="ilikesamsung";
    // std::vector<std::string> B{"i", "like", "sam",
    // "sung", "samsung", "mobile",
    // "ice","cream", "icecream", 
    // "man", "go", "mango"};
    
    std::string A="abcd";
    std::vector<std::string> B{"b", "d", "e", "p"};

    Solution solution;
    solution.wordBreak2(A,B);
}
#include <iostream>

class Solution{
private:
public:
    long long countWays(int n, int k){
        // long long int total=0;
        int M=1e9;
        M+=7;
        // std::cout << M;
        long long int total=0;
        long long int diff=k;
        long long int same=0;
        for (int i = 1; i <= n; i++)
        {
            total=(diff+same)%M;
            same=diff;
            diff=(total*(k-1))%M;
            // std::cout << total <<"\n";
        }
        return total;
    };
    Solution(){}
};

int main(){
    Solution solution;
    std::cout << solution.countWays(3,2);
}
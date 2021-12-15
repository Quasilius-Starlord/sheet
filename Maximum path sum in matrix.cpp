#include <iostream>
#include <vector>

class Solution{
private:
    int tracker(int i, int j, int N, std::vector<std::vector<int>>& Matrix){
        if(i<0 || j<0)
            return 0;
        if(i>N-1 || j>N-1)
            return 0;
        else
            return Matrix[i][j];
    };
    int maxrange(int a, int b, int c){
        return std::max(std::max(a, b), c);
    }
public:
    int maximumPath(int N, std::vector<std::vector<int>> Matrix)
    {
        // code here
        // int r=Matrix.size();
        // int c=Matrix[0].size();

        if(N==1)
            return Matrix[0][0];

        long long int dp[N];
        for (int i = 0; i < N; i++)
            dp[i]=Matrix[0][i];
        
        for (int i = N-2; i >=0; i--){
            for (int j = 0; j < N; j++)
            {
                Matrix[i][j]+=this->maxrange(this->tracker(i+1,j-1,N,Matrix),
                                                this->tracker(i+1,j+1,N,Matrix),
                                                    this->tracker(i+1,j,N,Matrix));
            }
        };

        int acc=0;
        for (int i = 0; i < N; i++){
            // std::cout << Matrix[0][i] << " ";
            acc=std::max(acc, Matrix[0][i]);
        }
        return acc;
        // return 0;
    }
};

int main(){
    Solution soluton;
    std::vector<std::vector<int>> Matrix={{1,2,3},{4,5,6},{7,8,9}};
    soluton.maximumPath(Matrix.size(),Matrix);
}
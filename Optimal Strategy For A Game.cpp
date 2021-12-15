#include <iostream>

class Solution{
    private:
        void shifter(int* arr, int* i, int* j){
            if(arr[*i]>arr[*j]){
                *i=(*i)+1;
            }else{
                *j=(*j)-1;
            }
        };

        long long helper(int* arr, long long** dp, int i, int j){
            if(i>j)
                return 0;
            if(dp[i][j]!=-1)
                return dp[i][j];
            
            // std::cout << i << ' ' << j << "here\n";
            long long left=arr[i]+std::min(this->helper(arr,dp,i+2,j), this->helper(arr,dp,i+1,j-1));
            long long right=arr[j]+std::min(this->helper(arr,dp,i,j-2), this->helper(arr,dp,i+1,j-1));

            return std::max(left,right);
        };
    public:
        long long maximumAmount(int arr[], int n){
            // Your code here
            long long** dp=new long long*[n];
            for (int i = 0; i < n; i++)
                dp[i]=new long long[n];
            
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dp[i][j]=-1;
                }
            }
            
            return this->helper(arr,dp,0,n-1);
        }
};

int main(){
    int N = 4;
    int A[] = {8,15,3,7};
    Solution solution;
    std::cout << solution.maximumAmount(A,N);
}
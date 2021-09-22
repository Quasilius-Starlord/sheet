#include <iostream>

class Solution{
private:

    long long int sum(int N, int arr[]){
        long long int acc=0;
        for (int i = 0; i < N; i++)
            acc+=arr[i];
        return acc;
    }

    bool containerBreach(int arr[],int a, int b, int i, int N){
        if( i>=N )
            return (a-b)==0 ? true : false;
        std::cout << a-b << " " << arr[i] <<  "\n";
        return this->containerBreach(arr,a+arr[i],b,i+1,N) | this->containerBreach(arr,a,b+arr[i],i+1,N);
    };
public:
    int equalPartition1(int N, int arr[])
    {
        // long long int
        return this->containerBreach(arr,arr[0],0,1,N) ? 1 : 0;
    };

    int equalPartition(int N, int arr[])
    {
        long long int acc=this->sum(N, arr);
        if(acc&1)
            return 0;
        
        long long int sumhalf=acc/2;
        std::cout << sumhalf << "\n";

        bool dp[N+1][sumhalf+1];
        dp[0][0]=true;
        for (int i = 1; i < sumhalf+1; i++)
            dp[0][i]=false;
        
        for (int i = 1; i < N+1; i++)
            dp[i][0]=true;
        
        acc=0;
        for (int i = 1; i < N+1; i++)
        {
            acc+=arr[i-1];
            for (int j = 1; j < sumhalf+1; j++)
            {
                dp[i][j]=dp[i-1][j];
                if(acc<j)
                    break;
                if(j>=arr[i-1]){
                    dp[i][j]=dp[i][j] || dp[i-1][j-arr[i-1]]; 
                }
                // std::cout << dp[i][j] << dp[i-1][j] << " ";
            }
            // std::cout << "\n";
        }
        for (int i = 0; i < N+1; i++)
        {
            for (int j = 0; j < sumhalf+1; j++)
            {
                // std::cout << dp[i][j] << " ";
            }
            // std::cout << "\n";
        }
        return dp[N][sumhalf];
        
    };
};

int main(){
    Solution solution;
    // int N=4;
    // int arr[]={1,5,11,5};
    int N=5;
    int arr[]={2,4,11,10,5};
    std::cout << solution.equalPartition(N,arr);
}
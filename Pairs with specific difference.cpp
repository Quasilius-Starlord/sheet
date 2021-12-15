#include <iostream>
#include <algorithm>

class Solution{
private:
public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here
        int ans=0;
        std::sort(arr,arr+N,[](const int& left,const int& right){
            return left > right;
        });
        for (int i = 0; i < N; i++)
        {
            // std::cout << arr[i] << " ";
        }
        int i=0;
        while ( i < (N-1) )
        {
            if(arr[i]-arr[i+1] < K){
                ans+=arr[i]+arr[i+1];
                i=i+2;
                continue;
            }else{
                i++;
                continue;
            }
        }
        std::cout << ans;
        return ans;
    }
};

int main(){
    Solution solution;
    int arr[]={3, 5, 10, 15, 17, 12, 9};
    int N=7;
    solution.maxSumPairWithDifferenceLessThanK(arr,N,4);
}

// https://www.youtube.com/watch?v=p66oF24dDg8
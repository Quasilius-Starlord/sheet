#include <iostream>

class Solution{
private:
    int getminindex(int arr[], int t){
        int index=-1;
        for (int i = 0; i < t; i++){
            if(arr[i] < 0){
                if(index==-1){
                    index=i;
                    continue;
                }
                index=arr[i] > arr[index] ? i : index;
            }
        }
        return index;
    };
    long long max(long long a, long long b){
        return a >= b ? a : b;
    }
public:
    long long maxSubarraySum(int arr[], int n){
        // Your code here
        // long long int sum=0;
        // int minin=this->getminindex(arr,n);
        // sum=arr[minin];
        
        long long sum=arr[0];
        long long coin=arr[0];
        for (int i = 1; i < n; i++)
        {
            if( coin+arr[i]>arr[i] ){
                coin+=arr[i];
                sum=this->max(sum, coin);
            }else{
                coin=arr[i];
                sum=this->max(sum, arr[i]);
            }
        }
        // int acc=arr[0];
        // for (int i = 0; i < n; i++)
        //     acc=arr[i]>acc ? arr[i] : acc;
        return sum;
    }
};

int main(){
    Solution solution;
    int arr[]={1, 2, 3, -2, 5};
    std::cout << solution.maxSubarraySum(arr,5);
}
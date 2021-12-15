#include <iostream>
#include <algorithm>
#include <vector>

class Solution{
private:
    void print(int arr[], int n){
        for (int i = 0; i < n; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    };

    bool lesstest(std::vector<int>& arr, int num){
        for (int i = 0; i < arr.size(); i++)
        {
            if(num<arr[i])
                return true;
        }
        return false;
    }

    int helper(int arr[], int k, int i, int j){
        if(i>j)
            return -1;
        if(i==j)
            return 0;
        
        int firstcall=arr[j]-arr[i]-k;
        int secondcall=arr[j]-arr[i]-(2*k);

        if(firstcall>=0 && secondcall>=0){
            return std::min(firstcall,secondcall);
        }else if(secondcall<0){
            if(firstcall>=0)
                return firstcall;
        }else if(firstcall<0){
            if(secondcall>=0)
                return secondcall;
        }
        if(firstcall<0 && secondcall<0){
            int left=this->helper(arr,k,i+1,j);
            int right=this->helper(arr,k,i,j-1);
            if(right<0 && left<0)
                return arr[j]-arr[i];
        }
    }
public:
    void printvec(std::vector<int>& arr){
        for (int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
        
    }
    int mindiff(int arr[], int n, int k){
        std::sort(arr,arr+n);

        int minima=arr[0],maxima=arr[n-1],ans=maxima-minima;
        // std::cout << ans << " ";
        for (int i = 0; i < n-1; i++)
        {
            maxima=std::max(arr[n-1]-k,arr[i]+k);
            minima=std::min(arr[0]+k,arr[i+1]-k);
            if(maxima-minima<0)
                continue;
            ans=std::min(ans,maxima-minima);
        }
        std::cout << ans;
        return ans;
    }
};

int main(){
    // int arr[]={2, 6, 3, 4, 7, 2, 10, 3, 2, 1};
    // int n=10;
    // int k=5;
    int arr[]={1, 5, 8, 10};
    int n=4;
    int k=2;
    // int arr[]={11, 13, 15};
    // int n=3;
    // int k=5;

    Solution solution;
    solution.mindiff(arr,n,k);
}
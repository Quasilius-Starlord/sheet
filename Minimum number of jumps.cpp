#include <iostream>

class Solution{
private:
    int* dp;
public:
    Solution(){
        this->dp=nullptr;
    };
    int helper(int arr[],int i, int n){
        if(this->dp[i]!=-1)
            return this->dp[i];
        if(arr[i]==0){
            this->dp[i]=-1;
            return -1;
        }        
        if(arr[i]>=n-i-1){
            this->dp[i]=1;
            return 1;
        };

        int ans=-1;
        int sins;
        for (int j = i+1; j <= i+arr[i]; j++)
        {
            if(j>n-1)
                break;
            sins=this->helper(arr,j,n);
            if(sins==-1)
                continue;
            else{
                if(ans==-1){
                    ans=sins+1;
                    continue;
                }else{
                    ans=std::min(ans,sins+1);
                }
            }
        }
        this->dp[i]=ans;
        return ans;
    }
    
    int minJumps(int arr[], int n){
        this->dp=new int[n];
        for (int i = 0; i < n; i++)
            this->dp[i]=-1;
        this->dp[n-1]=0;
        this->dp[0]=this->helper(arr,0,n);
        
        for (int i = 0; i < n; i++)
            std::cout << this->dp[i] << " ";
        
        return this->dp[0];
    }
};

class Solution1{
private:
    //inclusive range
    int maxrange(int i, int j, int n, int arr[]){
        int acc=0;
        int index=i;
        if(j>n-1)
            j=n-1;
        int overhead=0;
        for (int k = i; k <= j; k++){
            if(arr[k]+k>acc){
                acc=arr[k]+k;
                index=k;
            }
            overhead++;
        }
            // acc=arr[k] > acc ? arr[k] : acc; 
        return index;
    };
public:
    int minJumps(int arr[], int n){
        int ans=0;
        bool flag=false;
        int i=0;
        int rangemax;
        int back=0;
        while(!flag){
            if(arr[back]==0)
                return -1;
            if(arr[back]>=(n-1-back)){
                ans++;
                break;
            }
            back=this->maxrange(back+1,back+arr[back],n,arr);
            ans++;
            // if(rangemax)
        }
        std::cout << ans;
        return ans;
    }
};

int main(){
    Solution1 solution;
    int n=15;
    int arr[n]={9, 10, 1, 2, 3, 4, 8, 0, 0, 0, 0, 0, 0,0,1};
    solution.minJumps(arr,n);
}
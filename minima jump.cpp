#include <iostream>

class Solution{
private:
public:
    int minimumjump(int arr[], int n){
        int jump=1;
        int step=arr[0];
        int maximumstep=-1;
        if(arr[0]==0)
            return -1;
        if(n==1)
            return 0;
        for (int i = 1; i < n; i++)
        {
            step--;
            maximumstep=std::max(i+arr[i],maximumstep);
            if(step==0){
                step=maximumstep-i;
                if(i==n-1)
                    return jump;
                jump++;
                maximumstep=0;
                if(step==0)
                    return -1;
            }
        }
        std::cout << jump << "\n";
        return jump;
    }
};

int main(){
    Solution solution;
            // 0 1 2 3 4
    int arr[]={1,2,1,2,1};
    int n=5;
    solution.minimumjump(arr, n);
}
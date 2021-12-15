#include <iostream>
#include <string>
#include <unordered_map>

class Solution{
private:
public:
    std::string zerosum(int arr[], int n){
        std::unordered_map<int,bool> pbox;
        int sum=arr[0];
        if(arr[0]==0){
            return "Yes";
        }
        int req;
        pbox[sum]=true;
        pbox[0]=true;
        for (int i = 1; i < n; i++)
        {
            if(arr[i]==0)
                return "Yes";
            else{
                req=sum+arr[i];
                if(pbox.find(req)!=pbox.end())
                    return "Yes";
                
                sum+=arr[i];
                pbox[sum]=true;
            }
        }
        return "No";
    }
};

int main(){
    int arr[]={1, 2, 3, 4, 5};
    int n=5;
    Solution solution;
    std::cout << solution.zerosum(arr, n);
}
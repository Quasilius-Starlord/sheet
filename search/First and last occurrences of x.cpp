#include <iostream>
#include <vector>

class Solution{
private:
public:
    std::vector<int> find(int arr[], int n , int x )
    {
        // code here
        std::vector<int> ans;

        int low=0, high=n-1, mid;
        while (low<=high)
        {
            mid=(low+high)/2;
            if(arr[mid]>=x){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        // std::cout << low << " " << mid << " " << high << "\n";
        if(arr[low]==x)
            ans.push_back(low);
        else{
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        low=0;
        high=n-1;
        while (low<=high)
        {
            mid=(low+high)/2;
            if(arr[mid]<=x){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        // std::cout << low << " " << mid << " " << high << "\n";
        ans.push_back(high);
        return ans;
    }
};

int main(){
    Solution solution;
    int arr[]={ 1, 3, 5, 5, 5, 5, 67, 123, 125 };
    solution.find(arr,9,5);
}
#include <iostream>
#include <vector>

class Solution{
private:
public:
    int AlternatingaMaxLength(std::vector<int>&nums){
        if(nums.size()==1){
            return 1;
        }

        int surge=nums[1]-nums[0];
        int step=2;
        if(surge==0){
            // surge=1;
            step=1;
        }
        int curr=nums[1];
        for (int i = 2; i < nums.size(); i++)
        {
            if(surge>0){
                if(( nums[i]-curr )<0){
                    step++;
                    // std::cout << nums[i] << " " << curr << " " << step << "\n";
                    surge=nums[i]-curr;
                    curr=nums[i];
                }else{
                    curr=nums[i];
                    // std::cout << curr << "\n";
                }
            }else if(surge<0){
                if(( nums[i]-curr )>0){
                    step++;
                    // std::cout << nums[i] << " " << curr << " " << step << "\n";
                    surge=nums[i]-curr;
                    curr=nums[i];
                }else{
                    curr=nums[i];
                    // std::cout << curr << "\n";
                }
            }else{
                step++;
                surge=nums[i]-curr;
                curr=nums[i];
            }
        }
        // std::cout << step;
        return step;
    }
};

int main(){
    std::vector<int> nums{9,9,19};
    Solution solution;
    solution.AlternatingaMaxLength(nums);
}
#include<iostream>
#include<bits/stdc++.h>
#include <vector>

class Solution{
private:
public:
    int getmin(int nums[], int k, int n){
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < n; i++){
            pq.push(nums[i]);
        }
        int ans;
        for (int i = 0; i < k; i++)
        {
            ans=pq.top();
            std::cout << ans << " ";
            pq.pop();
        }
        return ans;
    };
};

int main(){
    int nums[]={7, 10, 4, 20, 15};
    int n=5;

    Solution solution;
    solution.getmin(nums,4,n);
}
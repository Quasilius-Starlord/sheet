#include <iostream>
#include <unordered_map>

class Solution{
private:
public:
    int getPairsCount(int arr[], int n, int k) {
        int count=0;
        std::unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            if(map.find(arr[i])!=map.end()){
                map[arr[i]]++;
            }else{
                map[arr[i]]=1;
            }
        }
        int point;
        for (int i = 0; i < n; i++)
        {
            point=arr[i];
            map[point]--;
            if(map[point]==0){
                map.erase(point);
            }
            
            if(map.find(k-point)!=map.end()){
                count+=map[k-point];
            }
        }
        return count;
    }
};

int main(){
    int arr[]={1, 5, 7, 1};
    int n=4,k=6;
    Solution solution;
    std::cout << solution.getPairsCount(arr, n, k);
}
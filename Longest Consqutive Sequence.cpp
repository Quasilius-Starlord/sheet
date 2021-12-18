#include<iostream>
#include<unordered_map>

class Solution{
private:
public:
    int longestSequence(int arr[], int n){
        int count=0;
        std::unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
            map[arr[i]]=0;
        int current;
        for (int i = 0; i < n; i++)
        {
            if(map.find(arr[i])!=map.end()){
                //presnt in map
                for (current=arr[i]; map.find(current-1)!=map.end(); current--)
                {
                    map[arr[i]]+=map[current-1]+1;
                    map.erase(current-1);
                }
            }
        }
        for (auto i:map)
        {
            std::cout << i.first << " " << i.second << "\n";
            count=std::max(count, i.second+1);
        }
        return count;
    }
};

int main(){
    int arr[]={1,9,3,10,4,20,2};
    Solution solution;
    solution.longestSequence(arr,7);
}
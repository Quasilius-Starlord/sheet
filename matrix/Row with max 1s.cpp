#include <iostream>
#include <vector>

int indexOfOne(std::vector<int>& row, int n){
    if(row[n-1]==0)
        return -1;
    int low=0, high=n-1;
    int mid;
    while (high>=low)
    {
        mid=(low+high)/2;
        if(row[mid]==0){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    // std::cout << low << " " << mid << " " << high << "\n";
    return low;
};

class Solution{
private:
    //zero based index for n
    int indexOfOne(std::vector<int>& row, int low, int high){
        if(row[high]==0)
            return -1;
        int mid;
        while (high>=low)
        {
            mid=(low+high)/2;
            if(row[mid]==0){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    };
public:
    int rowWithMax1s(std::vector<std::vector<int>> arr, int n, int m) {
	    // code here
        // int maxiumons=0;
        int indexOfMaxOne=m;
        int rowMaxOne=-1;
        int specimen;
        int i,j;
        for (i = 0; i < n; i++)
        {
            specimen=this->indexOfOne(arr[i],0,arr[i].size()-1);
            if(specimen==-1)
                continue;
            else{
                indexOfMaxOne=specimen;
                rowMaxOne=i;
                break;
            }
        }
        for (i=i+1; i < n; i++)
        {
            if(arr[i][indexOfMaxOne]==0)
                continue;
            else{
                specimen=this->indexOfOne(arr[i],0,indexOfMaxOne);
                if(specimen<indexOfMaxOne){
                    indexOfMaxOne=specimen;
                    rowMaxOne=i;
                }
            }
        }
        // std::cout << rowMaxOne;
        return rowMaxOne;
	}
};

int main(){
    std::vector<std::vector<int>> array={{0, 1, 1, 1}, {0, 0, 1, 1}, {0, 1, 1, 1}, {0, 0, 0, 0}};
    Solution solution;
    solution.rowWithMax1s(array,array.size(), array[0].size());
    // std::vector<int> row={0, 1};
    // indexOfOne(row, row.size()-1);
}
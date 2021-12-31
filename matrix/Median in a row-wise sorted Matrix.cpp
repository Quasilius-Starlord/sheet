#include <iostream>
#include <vector>

int countLessEq(std::vector<int>& row, int find, int n){
    int high=row.size()-1;
    int low=0,mid;
    // std::
    while (high>=low)
    {
        mid=(low+high)/2;
        if(row[mid]>find){
            high=mid-1;
        }
        else if(row[mid]<=find){
            low=mid+1;
        }
    }
    std::cout << find << " " << low << "\n";
    return low;
};

class Solution{
private:
    int countLessEq(std::vector<int>& row, int find, int n){
        int high=row.size()-1;
        int low=0,mid;
        // std::
        while (high>=low)
        {
            mid=(low+high)/2;
            if(row[mid]>find){
                high=mid-1;
            }
            else if(row[mid]<=find){
                low=mid+1;
            }
        }
        std::cout << find << " " << low << "\n";
        return low;
    };
    
    int countLessEq(std::vector<int>& row, int find, int n){
        int high=row.size()-1;
        int low=0,mid;
        // std::
        while (high>=low)
        {
            mid=(low+high)/2;
            if(row[mid]>find){
                high=mid-1;
            }
            else if(row[mid]<=find){
                low=mid+1;
            }
        }
        // std::cout << find << " " << low << "\n";
        return low;
    };
    int countLessEq(std::vector<std::vector<int>>& matrix, int mid, int m, int n){
        int count=0;
        for (int i = 0; i < m; i++){
            count+=this->countLessEq(matrix[i],mid,matrix[i].size());
        }
        return count;
    }
public:
    int median(std::vector<std::vector<int>> &matrix, int m, int n){
        // code here
        int medianind=(m*n+1)/2;
        int low=INT_MAX,high=-1;
        for (int i = 0; i < m; i++)
        {
            low=std::min(matrix[i][0],low);
            high=std::max(matrix[i][n-1],high);
        }
        std::cout << high << " " << low << "\n";
        int mid, count;
        while(high>=low){
            mid=(high+low)/2;
            count=this->countLessEq(matrix,mid,m,n);
            if(count>=medianind){
                high=mid-1;
            }else if(count<medianind){
                low=mid+1;
            }
        }
        return low;
    }
};

int main(){
    std::vector<std::vector<int>> matrix={{1}, {2}, {3}};
    // std::vector<std::vector<int>> matrix={{2,3,5}, {2,6,9}, {3,8,9}};
    Solution solution;
    std::vector<int> row={2,4,6,8,10};
    // std::cout << countLessEq(row, 2, row.size());
    solution.median(matrix,matrix.size(),matrix[0].size());
}
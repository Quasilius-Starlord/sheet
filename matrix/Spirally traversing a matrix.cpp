#include <iostream>
#include <vector>

class Solution{
private:
public:
    std::vector<int> spirallyTraverse(std::vector<std::vector<int> > matrix, int m, int n) 
    {
        // code here
        int leftlimit=0,rightlimit=n-1,up=0,down=m-1;
        int i=up,j=leftlimit;
        std::vector<int> mat;
        while (up<down && leftlimit<rightlimit)
        {
            //upper row
            i=up;j=leftlimit;
            for(j=leftlimit;j<=rightlimit;j++)
            {
                mat.push_back(matrix[i][j]);
                std::cout << matrix[i][j] << " ";
            }
            //right column
            j=rightlimit;
            if(down-up>1)
            {
                for(i=up+1;i<down;i++)
                {
                    mat.push_back(matrix[i][j]);
                    std::cout << matrix[i][j] << " ";
                }
            }
            //lower row
            i=down;
            for(j=rightlimit;j>=leftlimit;j--)
            {
                mat.push_back(matrix[i][j]);
                std::cout << matrix[i][j] << " ";
            }
            //left column
            j=leftlimit;
            if(down-up>1)
            {
                for(i=down-1;i>up;i--)
                {
                    mat.push_back(matrix[i][j]);
                    std::cout << matrix[i][j] << " ";
                }
            }
            //
            leftlimit++;rightlimit--;
            up++;down--;
        }
        if(up==down){
            i=up;
            for (j = leftlimit; j <= rightlimit; j++)
            {
                mat.push_back(matrix[i][j]);
                std::cout << matrix[i][j] << " ";
            }
        }else if(leftlimit==rightlimit){
            j=leftlimit;
            for (i = up; i <= down; i++)
            {
                mat.push_back(matrix[i][j]);
                std::cout << matrix[i][j] << " ";
            }
            
        }
        
        return mat;
    }
};

int main(){
    std::vector<std::vector<int>> martix={{1, 2, 3, 4}};
                                         {5, 6, 7, 8},
                                         {9, 10, 11, 12},
                                         {13, 14, 15,16}};
    Solution solution;
    std::vector<int> m=solution.spirallyTraverse(martix,martix.size(), martix[0].size());
}
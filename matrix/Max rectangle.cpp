#include <iostream>
#include <stack>

#define MAX 4

int findMaxArea(int arr[], int n){
    std::stack<int> Stack;
    // Stac
    int left[n];
    int right[n];
    // int bp=0;
    int top=0,limit=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==0){
            left[i]=i;
            top=i+1;
            limit=i+1;
            while (!Stack.empty())
                Stack.pop();
            continue;
        }
        while (!Stack.empty())
        {
            if(arr[Stack.top()]>=arr[i]){
                top=Stack.top();
                Stack.pop();
            }else{
                left[i]=Stack.top()+1;
                Stack.push(i);
                break;
            }
        }
        if(Stack.empty()){
            left[i]=limit;
            Stack.push(i);
        }
        
    }
    while (!Stack.empty())
        Stack.pop();
    top=n-1;
    limit=n-1;
    for (int i = n-1; i >= 0; i--)
    {
       if(arr[i]==0){
            right[i]=i;
            top=i-1;
            limit=i-1;
            while (!Stack.empty())
                Stack.pop();
            continue;
        }
        while (!Stack.empty())
        {
            if(arr[Stack.top()]>=arr[i]){
                top=Stack.top();
                Stack.pop();
            }else{
                right[i]=Stack.top()-1;
                Stack.push(i);
                break;
            }
        }
        if(Stack.empty()){
            right[i]=limit;
            Stack.push(i);
        }
    }
    int area=0;
    for (int i = 0; i < n; i++)
        std::cout << left[i] << " ";
    std::cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << right[i] << " ";
    std::cout << "\n";
    for (int i = 0; i < n; i++)
    {
        area=std::max(area,arr[i]*(right[i]-left[i]+1));
        std::cout << arr[i]*(right[i]-left[i]+1) << " ";
    }
    std::cout << "\n";
    return area;
}

class Solution{
private:
    std::stack<int> Stack;
    int maxAreaHistogram(int arr[], int* left, int* right, int n){
        
        while (!this->Stack.empty())
            this->Stack.pop();
        int top=0,limit=0;

        for (int i = 0; i < n; i++)
        {
            if(arr[i]==0){
                left[i]=i;
                top=i+1;
                limit=i+1;
                while (!this->Stack.empty())
                    this->Stack.pop();
                continue;
            }
            while (!this->Stack.empty())
            {
                if(arr[this->Stack.top()]>=arr[i]){
                    top=this->Stack.top();
                    this->Stack.pop();
                }else{
                    left[i]=this->Stack.top()+1;
                    this->Stack.push(i);
                    break;
                }
            }
            if(this->Stack.empty()){
                left[i]=limit;
                this->Stack.push(i);
            }
            
        }
        while (!this->Stack.empty())
            this->Stack.pop();
        top=n-1;
        limit=n-1;
        for (int i = n-1; i >= 0; i--)
        {
            if(arr[i]==0){
                right[i]=i;
                top=i-1;
                limit=i-1;
                while (!this->Stack.empty())
                    this->Stack.pop();
                continue;
            }
            while (!this->Stack.empty())
            {
                if(arr[this->Stack.top()]>=arr[i]){
                    top=this->Stack.top();
                    this->Stack.pop();
                }else{
                    right[i]=this->Stack.top()-1;
                    this->Stack.push(i);
                    break;
                }
            }
            if(this->Stack.empty()){
                right[i]=limit;
                this->Stack.push(i);
            }
        }
        int area=0;
        // for (int i = 0; i < n; i++)
        //     std::cout << left[i] << " ";
        // std::cout << "\n";
        // for (int i = 0; i < n; i++)
        //     std::cout << right[i] << " ";
        // std::cout << "\n";
        for (int i = 0; i < n; i++)
        {
            area=std::max(area,arr[i]*(right[i]-left[i]+1));
            std::cout << arr[i]*(right[i]-left[i]+1) << " ";
        }
        std::cout << "\n";
        return area;
    }
public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int* arr=new int[m];
        for (int i = 0; i < m; i++)
            arr[i]=0;
        int* left=new int[m];
        int* right=new int[m];
        int area=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(M[i][j]==0)
                    arr[j]=0;
                else
                    arr[j]+=1;
            }
            area=std::max(area,this->maxAreaHistogram(arr,left,right,m));
        }
        std::cout << area;
        return area;
    }
};

int main(){
    Solution solution;
    int row[]={0,2,4,6,6,5};
    // findMaxArea(row,6);
    int matrix[MAX][MAX]={{0, 1, 1, 0},
                          {1, 1, 1, 1},
                          {1, 1, 1, 0},
                          {1, 1, 0, 0}};
    solution.maxArea(matrix, 4 ,4);
}
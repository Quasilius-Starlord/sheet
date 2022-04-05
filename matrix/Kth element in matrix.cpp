#include <iostream>
#include <queue>
#include <vector>

#define MAX 10

struct Node{
    int value;
    int row;
    int column;
    Node(){
        this->value=0;
        this->row=0;
        this->column=0;
    };
    Node(int v, int r, int c){
        this->value=v;
        this->row=r;
        this->column=c;
    };
};

struct NodeComparator
{
    bool operator()(Node const& a, Node const& b){
        return a.value>b.value;
    };
};


class Solution{
private:
    int countLessEq(int row[], int find, int n){
        if(n==0)
            return 0;
        int high=n-1;
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
        return low;
    };
    int countLessEq(int matrix[MAX][MAX], int mid, int n){
        int count=0;
        int index=n;
        for (int i = 0; i < n; i++){
            index=this->countLessEq(matrix[i],mid,index);
            count+=index;
        }
        return count;
    };
public:
    int kthsmallestPriortyQueue(int matrix[MAX][MAX], int n, int k){
        std::priority_queue<Node,std::vector<Node>,NodeComparator> queue;
        for (int i = 0; i < n; i++)
            queue.push(Node{matrix[0][i],0,i});
        
        Node node;
        for (int i = 0; i < k; i++)
        {
            node=queue.top();
            if(node.row<n){
                queue.push(Node{matrix[node.row+1][node.column],node.row+1,node.column});
            }
        }
        return node.value;
    }
    int kthsmallestBinarySearch(int matrix[MAX][MAX], int n, int k){
        int high=matrix[n-1][n-1];
        int low=matrix[0][0];
        int mid,count;
        while (high>=low)
        {
            mid=(high+low)/2;
            count=this->countLessEq(matrix,mid,n);
            if(count>=k){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        std::cout << low << " " << mid << " " << high << "\n";
        return low;
    }
};

int main(){
    int matrix[MAX][MAX]={{16, 28, 60, 64},
                            {22, 41, 63, 91},
                            {27, 50, 87, 93},
                            {36, 78, 87, 94 }};
    Solution solution;
    int k=3;
    Node node{2,5,7};
    solution.kthsmallestPriortyQueue(matrix,4, k);
    
    // solution.kthsmallestBinarySearch(matrix,4,k);

}
#include<iostream>
#include<cmath>
using namespace std;
class Solution{
private:
	void swap(int *a, int *b){
		int term=*a;
		*a=*b;
		*b=term;
	};
public:
	void maxcost(int arr1[], int arr2[], int n, int m){
		int gap=m+n;	
		int i=0,j=0;
		int *left,*right;
		bool flag=true;
		while(flag){
			gap=ceil((double)gap/2);
			if(gap<=1)
				flag=false;
            // cout << "aee";
			i=0;j=i+gap;
			while((i+gap)<(m+n)){
				if(i<n)
					left=arr1+i;
				else
					left=arr2+i-n;
				
				if((i+gap)<n)
					right=arr1+i+gap;
				else
					right=arr2+i+gap-n;
				
				if((*left)>(*right)){
					this->swap(left,right);
				}
				i++;
			}
		}
	};
};
	void print(int arr[], int n){
		//cout << "aee";
		for(int i=0;i<n;i++)
			cout << arr[i] << " ";
	};

int main(){
	
	int arr1[]={1,2,6,9};
	int arr2[]={0,3,5,7};
	int n=4,m=4;
	Solution s;
	//cout << "aee";
	//s.maxcost(nums,3,1);
	s.maxcost(arr1,arr2,n,m);
	
	print(arr1, n);
	print(arr2, m);
}
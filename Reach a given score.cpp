#include <iostream>
#include <cstring>

long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 // If 0 sum is required number of ways is 1.
	
	// Your code here
	int arr[3]={3,5,10};

    for (int i = 3; i < n+1; i++)
        table[i]+=table[i-3];
    
    for (int i = 5; i < n+1; i++)
        table[i]+=table[i-5];
    
    for (int i = 10; i < n+1; i++)
        table[i]+=table[i-10];
    
	return table[n];
};

int main(){
    std::cout << count(20);
}
#include <iostream>
#include <vector>

class Solution{
public:
    long long max(long long a, long long b){
        return a>b ? a : b;
    };
    long long min(long long a, long long b){
        return a>b ? b : a;
    };
	// Function to find maximum product subarray
	long long maxProduct(std::vector<int> arr, int n) {
	    // code here
        long long answer=arr[0],total=arr[0];
        long long maxima_posetive=1, maxima_negetive=1;
        int i=0;
        while (1){
            // i++;
            if(i==n)
                break;

            if(arr[i]!=0){
                total=arr[i];
                answer=std::max((long long)arr[i],answer);
                i++;
                break;
            }
            i++;
        }
        // std::cout << total << " " << i << " " << maxima_negetive << " " << maxima_posetive << "\n"; 
        for (i; i < n; i++)
        {
            if(arr[i]==0){
                answer=std::max(answer, (long long)0);
                maxima_negetive=1;
                maxima_posetive=1;
                if(i!=n-1){
                    i++;
                    total=arr[i];
                    answer=std::max(answer, (long long)0);
                }
                continue;
            }
            if(arr[i]>0){
                if(total>0){
                    maxima_posetive=total*arr[i];
                    answer=std::max(answer, maxima_posetive);
                }else{
                    maxima_posetive=std::max(maxima_posetive, maxima_posetive*arr[i]);
                    answer=std::max(maxima_posetive, answer);
                    maxima_negetive=total*arr[i];
                }
            }else{
                if(total<0){
                    maxima_posetive=std::max(maxima_posetive*arr[i], maxima_posetive);
                    answer=std::max(answer, maxima_posetive);
                    maxima_negetive=std::min(maxima_negetive,(long long)arr[i]);
                }else{
                    answer=std::max(answer, (long long)arr[i]);
                    maxima_negetive=total*arr[i];
                }
            }
            total*=arr[i];
        }
        return answer;
	};
    void swap(long long *a, long long *b){
        long long temp;
        temp=*a;
        *a=*b;
        *b=temp;
    }
    long long draft2(std::vector<int>& arr, int n){
        long long maxima=arr[0];
        long long minima=arr[0];
        long long result=arr[0];
        long long new_minima, new_maxima;
        for (int i = 1; i < n; i++)
        {
            if(arr[i]==0){
                result=std::max(result, (long long)arr[i]);
                if(i<n){
                    i++;
                    maxima=arr[i];
                    minima=arr[i];
                    continue;
                }
            }
            if(arr[i]<0){
                this->swap(&maxima, &minima);
            }
            maxima=std::max((long long)arr[i], maxima*arr[i]);
            minima=std::min((long long)arr[i], minima*arr[i]);
            result=std::max(result,maxima);
        }
        return result;
    }
};

int main(){
    std::vector<int> arr={0,0,5};
    Solution solution;
    std::cout << solution.draft2(arr, arr.size());
}
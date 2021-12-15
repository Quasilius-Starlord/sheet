#include <iostream>
#include <vector>
#include <algorithm>

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
    Job(int a, int b, int c){
        id=a;
        dead=b;
        profit=c;
    }
};

class Solution{
private:
    int* dpcount;
    int* dpcost;
    void assign(int* dp, int i){
        for (int j = i; j >=0; j--)
        {
            if(dp[j]==-1){
                dp[j]=i;
                break;
            }
        }
    };

    void assassination(int *dp, int begin, int index){
        // std::cout << begin << " " << index << "\n";
        for (int i = begin; i >= 0 ; i--)
        {
            if(dp[i]==-1){
                dp[i]=index;
                break;
            }
        }
    }
public:
    std::vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        std::vector<int> soln;
        std::sort(arr,arr+n,[](const Job& left, const Job& right){
            return left.profit>right.profit;
        });

        // for (int i = 0; i < n; i++)
        // {
        //     /* code */
        // }
//         17
// 1 56 288 2 27 435 3 67 401 4 64 368 5 94 248 6 54 361 7 43 108 8 96 167 9 73 251 10 96 170 11 14 156 12 78 184 13 61 370 14 77 424 15 68 397 16 40 375 17 36 218

        int dp[n];

        for (int i = 0; i < n; i++)
            dp[i]=-1;
        // dp[0]=arr[0].dead-1;

        for (int i = 0; i < n; i++)
        {
            if(arr[i].dead>n){
                this->assassination(dp,n-1,i);
            }else{
                this->assassination(dp,arr[i].dead-1,i);
            }
        }
        


        // for (int i = 0; i < n; i++)
        // {
        //     if(dp[arr[i].dead-1]==-1)
        //         dp[arr[i].dead-1]=i;
        //     else{
        //         this->assign(dp,arr[i].dead-1);
        //     }
        // }

        // for (int i = 0; i < n; i++)
        // {
        //     std::cout << arr[i].profit << " " << arr[i].dead << "\n";
        // }
        //     std::cout << "\n";
        // for (int i = 0; i < n; i++)
        // {
        //     std::cout << dp[i] << " ";
        // }


        //count mech
        int count=0;
        int sum=0;
        for (int i = 0; i < n; i++)
        {
            if(dp[i]!=-1){
                count++;
                sum+=arr[dp[i]].profit;
            }
        }
        soln.push_back(sum);
        soln.push_back(count);
        // std::cout << totalprofit << " " << count;
        return soln;
    } 
};

int main(){
    Job arr[]={Job(1,2,100),Job(2,1,19),Job(3,2,27),Job(4,1,25),Job(5,1,15)};
    Solution solution;
    solution.JobScheduling(arr,5);
}
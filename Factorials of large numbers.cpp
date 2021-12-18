#include <iostream>
#include <vector>

class Solution{
private:
    void distribution(std::vector<int>& num, int carry){
        while (carry>0)
        {
            num.push_back(carry%10);
            carry=carry/10;
        }
    };
    void exchange(std::vector<int>& num){
        int i=0,j=num.size()-1;
        int temp;
        while(i<j){
            //exchange
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
            //exchange done
            i++;j--;
        }
    }
public:
    std::vector<int> factorial(int N){
        // code here
        std::vector<int> num;
        num.push_back(1);
        if(N==1)
            return num;
        int carry=0;
        int result,i,j;
        for (i = 1; i <= N; i++)
        {
            carry=0;
            for (j = 0; j < num.size(); j++)
            {
                // std::cout << "here\n";
                result=i*num[j];
                result+=carry;
                carry=0;
                if(result<10){
                    num[j]=result;
                }else{
                    num[j]=result%10;
                    carry=result/10;
                }
            }
            while (carry>0)
            {
                num.push_back(carry%10);
                carry=carry/10;
            }
        }
        int temp;
        i=0;j=num.size();
        while(i<j){
            //exchange
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
            //exchange done
            i++;j--;
        }
        return num;
        for (int i = 0; i < num.size(); i++)
        {
            std::cout << num[i] << " ";
        }

        return num;
    }
};

int main(){
    int n=10;
    Solution solution;
    std::vector<int> v=solution.factorial(n);
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    
}
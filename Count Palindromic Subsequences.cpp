#include <iostream>
#include <string>

class Solution{
private:
    long long int** dp;
    long long int M;
    long long int helper(std::string str, int i, int j){
            // std::cout << str[i] << " " << str[j] << " " << i << " " << j << "\n";
        if(i>j)
            return 0;
        
        if(this->dp[i][j]!=-1)
            return this->dp[i][j];
        
        long long int sum=0;

        // long long int
        if(str[i]==str[j]){
            sum+=1;
            sum=(sum+this->helper(str,i,j-1))%this->M;
            sum=(sum+this->helper(str,i+1,j))%this->M;
            // sum=(sum+this->helper(str,i,j-1)+this->helper(str,i+1,j))%M;
            // sum=(sum+this->helper(str,i+1,j))%M;
        }else{
            sum=(sum+this->helper(str,i,j-1))%this->M;
            sum=(sum+this->helper(str,i+1,j))%this->M;
            sum=(sum-this->helper(str,i+1,j-1))%this->M;
            
            if(sum<0){
                std::cout << sum << " " << i << " " << j << "\n";
                sum+=this->M;
                // exit(0);
            }
            // sum=(sum+this->helper(str,i,j-1)+this->helper(str,i+1,j)-this->helper(str,i+1,j-1))%M;
            // sum=(sum+this->helper(str,i+1,j))%M;
            // sum=(sum-this->helper(str,i+1,j-1))%M;
        }
        // std::cout << sum << " ";
        this->dp[i][j]=sum;
        return sum;
    };
public:
    long long int countPS(std::string str)
    {
        // Your code here
        int n=str.size();
        this->dp=new long long int*[n];
        for (int i = 0; i < n; i++)
            this->dp[i]=new long long int[n];
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                this->dp[i][j]=-1;
        }


        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < n; j++)
        //         std::cout << this->dp[i][j] << " ";
        //     std::cout << "\n";
        // }

        long long int sum;
        sum=this->helper(str, 0, str.size()-1);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(this->dp[i][j]<0){}
                    // std::cout << this->dp[i][j] << " ";
            }
                // this->dp[i][j]=-1;
            // std::cout << "\n";
        }
        std::cout << sum;
        return sum;
    }

    long long int helperexp(std::string str, int i, int j){
        if(i < 0 || j >= str.size()){
            return 0;
        }
        long long int sum=0;
        int M=1e9;
        M+=7;

        if(str[i]==str[j]){
            sum+=1;
        };

        sum=(sum+this->helperexp(str,i-1,j+1))%M;

        return sum;
    }

    long long int countPS(std::string str, int a){
        long long int sum=0;
        int M=1e9;
        M+=7;

        if(str.size()==1)
            return 1;
        // long long int sum=0;
        for (int i = 0; i < str.size(); i++)
            sum=(sum+this->helperexp(str,i,i))%M;

        for (int i = 0; i < str.size()-1; i++)
            sum=(sum+this->helperexp(str,i,i+1))%M;
        std::cout << sum;
        return sum;
    }

    Solution(){
        this->dp=nullptr;
        this->M=1000000007;
        // this->M+=7;
        // std::cout << this->M;
    };
};

int main(){
    std::string str="mbcgepnkdqemhmkuqosgeonbcrphobcmbhrgppkfpdqckigsomktpsurknsospighufulqijcupisnuqcqfpuckrndmqeeklqfcrfnemeghmnlunlpslncqllmbebnoudihgpigrfbrqbcurmqnfroheqltkbnpocousjepehgppmblodppsqrglprtekmsqlqekhjseotocgkfcrkssmmenhitupdcoujscne";
    Solution solution;\
    // long long int s=214748364000%100000007;
    // std::cout << s;
    solution.countPS(str);
}
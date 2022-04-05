#include<iostream>
#include<string>

class Solution{
private:
public:
    std::string longestPalin (std::string S) {
        // code here
        std::string longest="";
        int start=0,end=0,longestSize;
        for (int i = 0; i < S.size(); i++)
        {
            start=i;
            end=i;
            while (start>=0 && end<S.size())
            {
                if(S[start]==S[end]){
                    if((end-start+1)>longest.size()){
                        longest=S.substr(start, end-start+1);
                    }
                }else{
                    break;
                }
                start--;
                end++;
            }
            if(i==S.size()-1)
                break;
            start=i;
            end=i+1;
            while (start>=0 && end<S.size())
            {
                if(S[start]==S[end]){
                    if((end-start+1)>longest.size()){
                        longest=S.substr(start, end-start+1);
                    }
                }else{
                    break;
                }
                start--;
                end++;
            }
        }
        // std::cout << longest << "\n";
        return longest;
    }
};

int main(){
    Solution solution;
    solution.longestPalin("aaaabbaa");
}
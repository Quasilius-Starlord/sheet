#include <iostream>

class Solution{
private:
public:
    void sort012(int a[], int n)
    {
        int s0=0,s1=0,s2=0;

        for (int i = 0; i < n; i++)
        {
            switch (a[i])
            {
            case 0:
                s0++;
                break;
            case 1:
                s1++;
                break;
            case 2:
                s2++;
                break;
            default:
                break;
            }
        }
        int i = 0;
        for (i; i < s0; i++)
            a[i]=0;
        s0+=s1;
        for (i; i < s0; i++)
            a[i]=1;
        s0+=s2;
        for (i; i < s0; i++)
            a[i]=2;
    }
};

int main(){
    Solution solution;
    int a[]={0,2,1,2,0};
    solution.sort012(a,5);
    for (int i = 0; i < 5; i++)
    {
        std::cout << a[i] << " ";
    }
    
}
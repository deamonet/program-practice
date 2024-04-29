#include <stdio.h>
#include <iomanip>
#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        double zero = 0;
        double unit = 1;

        if(x==unit){return x;};
        if(n==0){return unit;};

        if(x == zero && n>0){
            return x;
        }else if(x == zero && n<0){
            return res / x;
        }else{
            if(n>0){
                while(n!=0){
                    res = res * x;
                    --n;
                };
            };

            if(n<0){
                while(n!=0){
                    res = res / x;
                    ++n;
                };
            };
        };
    return res;
    };

    double fastPow(double x, int n){
        double res = 1;
        double unit = 1;
        double zero = 0;

        if(n==0){return unit;};
        if(n==1){return x;};
        if(n==2){return x*x;};
        
        int mod = n % 2;
        int n2 = n / 2;
        if(mod == 0){
            res =  fastPow(x, n2);
            return res*res;
        }else{
            res = fastPow(x, n2);
            return res*res*x;
        }
    };

    double mypow2(double x, int n){
        if(n>=0){
            return fastPow(x, n);
        }else{
            double unit = 1;
            return unit / fastPow(x, n);
        };
    };
};

int main(){
    Solution s;
    double x=2.00000;
    for(int n=-31; n<32; n++){
        double res = s.mypow2(x, n);
        cout<<n<<"\t\t"<<res<<endl;
    };
};
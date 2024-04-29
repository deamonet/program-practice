#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        // dp(n) = dp(n-1) + dp(n-2)
        int data[n];
        for(int i=1; i<n; i++){data[i]==0;}

        return climb(n, *data);
    }

    int climb(int n, int data[])
    {
        if (n == 0)
        {
            data[n] = 0;
            return 0;
        }
        else if (n == 1)
        {
            data[n] == 1;
            return 1;
        }
        else if (n == 2)
        {
            data[n] == 2;
            return 2;
        }
        else
        {
            return climbStairs(n - 1) + data[n-2];
        }
    }
};

int main(){
    Solution s;
    int a = s.climbStairs(4);
    cout<<a;
}
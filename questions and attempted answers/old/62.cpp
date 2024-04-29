#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution1
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 || n == 1)
        {
            return 1;
        };

        double a = 1;
        for (int i = m, j = 1; i < m + n - 1 && j < n; i++, j ++)
        {
            a = a * ((double)i / (double)j);
            cout<< "a" << a << "\n";
            cout << "i" << i << "\n";
            cout << "j" << j << "\n";
        }

        return (int)a;
    }
};

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 || n == 1)
        {
            return 1;
        };

        long int a = 1, b= 1;
        for (int i = m, j = 1; i < m + n - 1 && j < n; i++, j++)
        {
            a = a * i; b = b * j;
            
        }

        return a / b;
    }
};

int main(){
    Solution s;
    int a = s.uniquePaths(3, 7);
    cout<<a;
}
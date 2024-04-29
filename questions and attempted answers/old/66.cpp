#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i]++;
            digits[i] = digits[i] % 10;
            if (digits[i] != 0)
            {
                return digits;
            }
        }
        vector<int> res;
        res.push_back(1);
        for (int j = 0; j < digits.size(); j++)
        {
            res.push_back(0);
        }
        return res;
    };
};
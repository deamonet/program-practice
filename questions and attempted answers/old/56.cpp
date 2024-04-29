#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res_interval;
        vector<vector<int>> temp_interval;
        res_interval.clear();temp_interval.clear();
        int length = intervals.size();
        if(length == 0)
        {
            return intervals;
        }
        else if(length == 1)
        {
            return intervals;
        }
        else if(length == 2)
        {
            vector<int> interval;
            vector<vector<int>> merge_interval;
            if(intervals[0][1] < intervals[1][0])
            {
                interval[0] = intervals[0][0];
                interval[1] = intervals[1][1];
                merge_interval[0] = interval;
                return merge_interval;
            }
            else if (intervals[1][1] < intervals[0][0])
            {
                interval[0] = intervals[1][0];
                interval[1] = intervals[0][1];
                merge_interval[0] = interval;
                return merge_interval;
            }
            else
            {
                return intervals;
            }
        }
        else
        {
            int middle = length / 2;
            for(int n=0; n<middle+1; n++)
            {
                temp_interval.clear();
                temp_interval.push_back(intervals[n]);
                temp_interval = merge(temp_interval);
                for(int m=0; m<temp_interval.size(); m++)
                {
                    res_interval.push_back(temp_interval[m]);
                }
            }
            for(int n=middle+1; n<length; n++)
            {
                temp_interval.clear();
                temp_interval.push_back(intervals[n]);
                temp_interval = merge(temp_interval);
                for (int m = 0; m < temp_interval.size(); m++)
                {
                    res_interval.push_back(temp_interval[m]);
                }
            }
            return res_interval;
        }
    }
};
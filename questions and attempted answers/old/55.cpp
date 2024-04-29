#include <vector>;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<int> zeros;
        zeros.clear();
        for (int i; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                return true;
            }
            else
            {
                zeros.push_back(i);
            }
        }
        
    }
};
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        if      (length == 0){return 0;}
        else if (length == 1){return nums[0];}
        else if (length == 2){
            if(nums[0]<nums[1]){return nums[1];}
            else{return nums[0];};
        }else{
            int middle = length / 2;
            vector<int> before, after;
            for(int i=0; i<length; i++){
                if(i<middle){before.push_back(nums[0]);}
                else{after.push_back(nums[i]);};
            };
            return maxSubArray(before) + maxSubArray(after);
        };
    };
};


int main(){
    Solution s;
    vector<int> nums;
    for(int i=0;i<5;i++){
        nums.push_back(i);
        cout<<nums[i]<<",";
    };
    cout<<"\n\n";

    int data = s.maxSubArray(nums);
    printf("finally");
    cout<<data;
    cout<<"\n\n";
}
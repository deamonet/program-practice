/*
 * @lc app=leetcode.cn id=136 lang=java
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
    public static void main(String[] args){
        int[] nums = {2, 2, 1, 3, 3, 4, 4, 5, 1};
        int ret = singleNumber(nums);
        System.out.println(ret);
        System.out.println(0 ^ 2);
    }
    
    public static int singleNumber(int[] nums) {
        int ret = nums[0];
        for (int i=1; i<nums.length; i++){
            ret = ret ^ nums[i];
        }
        return ret;
    }
}
// @lc code=end


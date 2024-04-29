/*
 * @lc app=leetcode.cn id=26 lang=java
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
    public int removeDuplicates(int[] nums) {
        int j = 0;
        for (int i=1; i<nums.length; i++){
            if (nums[j] != nums[i]){
                nums[j+1] = nums[i];
                j++;                
            }
        }
        return j+1;
    }
}
// @lc code=end


/*
 * @lc app=leetcode.cn id=15 lang=java
 *
 * [15] 三数之和
 */
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Collections;

// @lc code=start
class Solution {
    public static void main(String[] args){
        int[] nums = {-1,0,1,2,-1,-4};
        List<List<Integer>> ret = threeSum(nums);
        System.out.println(ret);
    }

    public static List<List<Integer>> threeSum(int[] nums) {
        List<Integer> path = new ArrayList<>();
        List<List<Integer>> ret = new ArrayList<>();
        boolean[] unused = new boolean[nums.length];
        for (int i=0; i<nums.length; i++){unused[i]=true;}
        if (nums.length < 3){
            return ret;
        }else{
            dfs(ret, path, 0, 0, unused, nums);
            return ret;
        }
    }

    public static void dfs(
        List<List<Integer>> ret,
        List<Integer> path,
        int depth,
        int sum,
        boolean[] unused,
        int[] nums
        ){
            boolean flag = false;
            List<Integer>  temp_path;
            if(depth == 3){
                if (sum == 0){
                    Collections.sort(path);
                    if (ret.isEmpty()){
                        flag = true;
                    } else {
                        for (int i=0; i<ret.size(); i++){
                            temp_path = ret.get(i);
                            for (int j=0; j<3; j++){
                                if (path.get(j) != temp_path.get(j)){
                                    flag = true;
                                }
                            }
                        }
                    }
                    if(flag){ret.add(new ArrayList<>(path));}
                }
                return;
            }

            for (int i=0; i<nums.length; i++){
                if (unused[i]){
                    unused[i] = false;
                    path.add(nums[i]);
                    dfs(ret, path, depth+1, sum + nums[i], unused, nums);
                    unused[i] = true;
                    path.remove(path.size()-1);
                }
            }   
    }
}
// @lc code=end
import java.util.ArrayList;

/*
 * @lc app=leetcode.cn id=920 lang=java
 *
 */

// @lc code=start
class Solution {
    static Integer ret;
    public static void main(String[] args){
        ret = numMusicPlaylists(6,10,2);
        System.out.println(ret);
    }

    public static int numMusicPlaylists(int n, int goal, int k) {
        ret = 0;
        ArrayList<Integer> options = new ArrayList<Integer>();
        ArrayList<Boolean> used = new ArrayList<Boolean>();
        // ArrayList<Integer> path = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {options.add(k);}
        for (int i = 0; i < n; i++) {used.add(false);}
        if (n == 0) {return ret;}
        dfs(0, options, used, n, goal, k);
        return ret;
    }
    
    public static void dfs(
            int depth,
            // ArrayList<Integer> path, 
            ArrayList<Integer> options,
            ArrayList<Boolean> used,
            int n, int goal, int k
            ){
        int temp;
        boolean temp2;
        int left = 0;

        for (Boolean b : used){
            if (!b){left++;}}

        if (depth == goal )
            {if (left == 0){ret++;}
            System.out.println(ret);
            return;} 

        for (int i=0; i<n; i++){
            if (options.get(i) >= k){
                temp = options.get(i);
                temp2 = used.get(i);
                // select one, every other one get advanced.
                for (int j=0; j<n; j++){options.set(j, options.get(j)+1);}
                options.set(i, 0);
                // make sure every song appeared at least once
                used.set(i, true);
                // path.add(i);
                // System.out.println(path);
                // System.out.println(used);
                dfs(depth+1, options, used, n, goal, k);
                // backtracking
                for (int j=0; j<n; j++){options.set(j, options.get(j)-1);}
                options.set(i, temp);
                used.set(i, temp2);
                // path.remove(path.size()-1);
            }
        }
    }
}
// @lc code=end


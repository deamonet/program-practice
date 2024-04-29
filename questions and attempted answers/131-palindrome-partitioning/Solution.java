import java.util.ArrayList;
import java.util.List;


public class Solution {

    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> path = new ArrayList<>();
        dfs(s, path, res);
        return res;
    }

    private void dfs(String s, List<String> path, List<List<String>> res) {
        
        if (s.length() == 0){
            res.add(new ArrayList<>(path));
            return;
        } else if (s.length() ==  1) {
            path.add(s.substring(0));
            res.add(new ArrayList<>(path));
            path.remove(path.size() - 1);
            return;
        } else {
            for (int i = 1; i < s.length()+1; i++) {
                if (isPalindrome(s.substring(0, i))){
                    path.add(s.substring(0, i));
                    dfs(s.substring(i), path, res);
                    path.remove(path.size() - 1);
                }
            }
    
        }
    }

    private static boolean isPalindrome(String s){
        for (int i=0, j=s.length()-1; i<s.length()/2+1; i++, j--){
            if (!(s.charAt(i) == s.charAt(j))){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String s = "aaaaaaaaaaaaaa";
        Solution solution = new Solution();
        List<List<String>> lists = solution.partition(s);
        System.out.println(lists);
    }
}
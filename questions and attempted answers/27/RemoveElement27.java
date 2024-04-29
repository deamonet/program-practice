public class RemoveElement27 {
    public static void main(String[] args){
        int[] nums = {3, 2, 2, 3};
        int val = 3;
        int len = removeElement(nums, val);
        System.out.println(len);
        for (int i : nums){
            System.out.println(i);
        }
        
    }

    public static int removeElement(int[] nums, int val) {
        if (nums.length == 0){
            return 0;
        } else {
            int cnt = 0;
            for (int i=0, j=nums.length-1; i<=j; i++, j--){
                if (nums[i]==val && nums[j]==val){
                    i--;
                    cnt++;
                } else if (nums[i]!=val && nums[j]!=val){
                    j++;
                } else if (nums[i]==val && nums[j]!=val){
                    nums[i] = nums[j];
                    cnt++;
                } else{
                    cnt++;
                    continue;
                }
            }
            return nums.length - cnt;
        }
    }
}

class RemoveDuplicatesFromSortedArray26 {
    public static void main(String[] args){
        int[] nums = {1, 2, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 7, 7, 7};
        int k = removeDuplicates(nums);
        System.out.println(k);
        for (int i : nums){
            System.out.print(i);
            System.out.print(", ");
        }
    }

    public static int removeDuplicates(int[] nums) {
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


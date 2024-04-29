import java.util.Arrays;
import java.util.Random;

public class InsertSort {
    public static void main(String[] args){
        int[] list = listGen(10, 10);
        System.out.println(Arrays.toString(list));
        int temp;
        for(int i=1; i<list.length; i++){
            if (list[i] >= list[i-1]){
                continue;
            }
            for(int j=i-1; j>=0; j--){
                if(list[j+1] < list[j]){
                    temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;
                    System.out.println(Arrays.toString(list));
                }
            }
        }
        System.out.println(Arrays.toString(list));
    }

    public static int[] listGen(int seed, int len){
        Random ran1 = new Random(seed);
        int[] myList = new int[len];
        for (int i=0; i<len; i++){
            myList[i] = ran1.nextInt(100);
        }
        return myList;
    }
}

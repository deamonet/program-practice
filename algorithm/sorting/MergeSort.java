import java.util.Random;
import java.util.Arrays;


public class MergeSort {
    public static void main(String[] args){
        int[] list = listGen(10, 20);
        System.out.println(Arrays.toString(list));
        int block;
        for (block = 1; block < list.length * 2; block *= 2){

        }

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

import java.util.Arrays;
import java.util.Random;

class BubbleSort{
    
    public static void main(String[] args){
        int[] list = BubbleSort.listGen(10, 10);
        System.out.println(Arrays.toString(list));
        int flag, temp;
        flag = 1;
        while (flag > 0){
            flag = 0;
            for (int i=0; i<list.length-1; i++){
                temp = list[i+1];
                if (list[i] > list[i+1]){
                    list[i+1] = list[i];
                    list[i] = temp;
                    flag++;
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
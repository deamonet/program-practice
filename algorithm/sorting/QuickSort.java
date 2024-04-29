public class QuickSort {
    
    public void sort(int[] list, int begin, int end){
        int pivot = list[begin];
        int i = begin;
        int j = end;
        while (i < j){
            while( i < j && list[j] > pivot){
                j--;
            }
            if (i<j){
                list[i] = list[j];
                i++;
            }
            while( i < j && list[i] < pivot){
                i++;
            }
            if()
        }
    }
}

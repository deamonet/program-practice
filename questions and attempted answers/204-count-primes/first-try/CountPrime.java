import java.util.Arrays;

public class CountPrime {
    public static void main(String[] args){
        int num = 4;
        int res = countPrimesDueN(num);
        System.out.println(res);
    }

    public static int countPrimesDueN(int n){
        int cnt = 0;
        int[] axis = new int[n+1];
        Arrays.fill(axis, 1);
        for(int i=2; i<n; i++){
            if (axis[i] == 1){
                cnt++;
                for (int j=i; j<=n/i; j++){
                    axis[i*j] = 0;
                }
            }
        }
        return cnt;
    }
    

    public static int countPrimes(int n) {
        int[] isPrime = new int[n];
        Arrays.fill(isPrime, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i] == 1) {
                ans += 1;
                if ((long) i*i < n){
                    for (int j=i*i; j<n; j+=i) {
                        isPrime[j] = 0;
                    }    
                }            }
        }
        return ans;
    }
}
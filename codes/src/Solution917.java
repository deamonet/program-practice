import java.lang.Character;
import java.lang.String;


public class Solution917 {
    public static void main(String[] args){
        String a = "a-bC-dEf-ghIj!kl+mnop?qrs=t-uvwx=yz";
//      extreme conditions
        String b = "Test1ng-Leedft=code-Q!!!--!";
        String c = "T!";
        String d = "!tdjf9oae0983174ur098jd098fu2-4398750928-20849-3284-0id-10389407398jr948u3785y90s8d0f921";
        System.out.println(reverseOnlyLetters(d));
    }

    public static String reverseOnlyLetters(String s) {
        StringBuilder sb = new StringBuilder(s.length());
        char a, b;
        for(int i = 0, j = s.length() - 1; i < s.length() && j >= 0; i++, j--){
            a = s.charAt(i);
            b = s.charAt(j);
            System.out.print(a);
            System.out.print(b);
//          a b both are letter
//          a b both take a step
            if (Character.isLetter(a) && Character.isLetter(b)){
                sb.append(b);
                System.out.print(b);
//          a b both are not a letter
//          a b both take a step
            } else if (!(Character.isLetter(a) || Character.isLetter(b))) {
                sb.append(a);
                System.out.print(a);
//          a is not a letter and b is a letter
//          b pause
            } else if (Character.isLetter(b)){
                sb.append(a);
                System.out.print(a);
                j++;
//                a is a letter and b is not a letter
//                a pause
            } else if (Character.isLetter(a)){
                i--;
            }
            System.out.print("\n");
        }
        String result = sb.toString();
        if (result.length() < s.length()){
            for (int i = 0; i < s.length() - result.length(); i++){
                sb.append(s.charAt(result.length() + i));
            }
        }
        return sb.toString();
    }
}
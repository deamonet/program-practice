import java.io.*;
import java.util.*;

public class Foo {
    public static void main(String[] args){
        String s = "com.jd.".replaceAll(".", "/") + "MyClass.class";
        System.out.println(s);
    }
}

public class MainMethodTester {
    // main 方法名加上 String[] args 的参数会被识别成主函数的方法名，不会当成普通方法。
    public static void main(){
        System.out.println("main");
        return;
    }

    public static void main(String args){
        System.out.println(args);
        return;
    }

    public static void main(String[] args){
        main("main");
        main();
        return;
    }
}
public class ExtendTest {
    public static void main(String[] args){
        new B().a();
    }
}

class A {
    void a(){
        b();
    }
    void b(){
        System.out.println("A");
    }
}

class B extends A{
    void b(){
        System.out.println("B");
    }
}
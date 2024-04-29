class Base {
    Base(){
        System.out.println("test");
    }
}


public class Derived extends Base{
    public static void main(String[] args){
        new Derived();
        new Base();
    }
}
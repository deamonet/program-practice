public class ContructMethodTester {
    public int a;
    public int b;
    public ContructMethodTester(){
        
    }

    public ContructMethodTester(int a, int b){
        this.a = a;
        this.b = b;
        this();
    }
}
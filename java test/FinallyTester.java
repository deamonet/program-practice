public class FinallyTester {
    public String Foo() {

        try {
            System.out.println("Inside try");
            return "from try";
        } finally {
            throw new RuntimeException();
        }

    }
}

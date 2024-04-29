java中继承,子类是否继承父类的构造函数

    java继承中子类是不会继承父类的构造函数的,只是必须调用(隐式或者显式)

下面来看例子:
public class TestExtends {
    public static void main(String[] args) {
        SonClass s = new SonClass(66);
    }
}

class FooClass{
    public FooClass() {
        System.out.println(100);
    }
    public FooClass(int count) {
        System.out.println(count);
    }
}

class SonClass extends FooClass{
    public SonClass() {
    }
    public SonClass(int c) {
        System.out.println(1234);
    }

}

运行结果:
100 1234

接下来分析为什么会产生这样的结果:
程序在执行SonClass s = new SonClass(66);这行时,调用
public SonClass(int c) {
    System.out.println(1234);  //在执行这行时系统会优先调用父类的无参构造函数super();
}

因此子类在执行上面的构造方法时,等价于执行了下面的代码:
public SonClass(int c) {
    super(); // 必须在第一行调用,否则不能编译
    System.out.println(1234);  //在执行这行时系统会优先调用父类的无参构造函数super();
}

所以结果为:
100 1234

接下来介绍另外一种情况（显式调用），如果子类构造函数是这样写的：
public SonClass(int c) {
    super(2); // 必须写在第一行,否则不能编译,显式调用父类构造函数后,系统就不在默认调用无参构造函数了
    System.out.println(1234);
}

执行结构是:
2 1234
总结:

        构造函数是不能继承的，只是用来在子类调用,（如果父类没有无参构造函数，创建子类时，必须在子类构造函数代码体的第一行显式调用父类的有参数构造函数，否则不能编译）;
        如果父类没有有参构造函数,那么在创建子类时可以不显式调用父类构造函数,系统会默认调用父类的无参构造函数super();
        如果父类没有无参构造函数,那系统就调不了默认的无参构造函数了,所以不显示调用编译也就无法通过了;

补充说明:

    在java中,创建有参构造函数后,系统就不在有默认的无参构造函数
    如果父类中没有任何构造函数,系统会默认有一个无参的构造函数

作者：程序员七哥
链接：https://www.jianshu.com/p/f7934687e420
来源：简书
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
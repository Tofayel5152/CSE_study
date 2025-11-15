package other;

public class A {

    public String name;
    protected String pass = "AAAA"; // Can't be accessed outside the package , can be access through child class.
    int marks = 100; // Defult type can't be accessed outside the other folder or packsage so Demo.java can't access it.

}

class Show{
    public void show(){
        A obj = new A();
        System.out.println(obj.pass); // Get access inside the same file and can get access in same package also can get access outside the package through child class or sub-class.(class C in Demo file)
    }
}

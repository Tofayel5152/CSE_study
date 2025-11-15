
    //import tools.Calc;
    //import tools.AdvCalc;
    // -- This two can be called togather
    //import tools.*;

    import other.tools.*;
    import other.A;

    class C extends A{
        public void show(){
            System.out.println("Pass: " + pass);
        }
    }
public class Demo {

        public static void main(String args[])
        {
    //		ArrayLis list=new ArrayList();
        
        Calc obj = new Calc();
        System.out.println(obj.add(10, 5));

        AdvCalc obj1 = new AdvCalc();
        
        System.out.println(obj1.multi(5, 2));
        
        A obj2 = new A();
        // System.out.println(obj2.marks); 
        // Can't be accessed cz A.java in another package and marks is not puublic.

        obj2.name = "REYNA";

        // System.out.println(obj2.pass); pass has protected access in A Can't access.
        C ob = new C();
        ob.show(); // Get access of pass through class C as it is a sub-class

        B obj3 = new B();

        System.out.println("Marks: " + obj3.marks); // Get accessed cz B.java is the same package.
        // System.out.println(obj3.mark); Can't get access cz it't private.

    }
}


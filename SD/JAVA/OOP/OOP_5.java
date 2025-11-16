/*
    Encapsulation: (Example in CODES.)
    Encapsulation is the process of combining data and functions into a single unit called class.
    In Encapsulation, the data is not accessed directly; it is accessed through the functions present inside the class. In simpler words, attributes of the class are kept private and public getter and setter methods are provided to manipulate these attributes. Thus, encapsulation makes the concept of data hiding possible. Means uses of access modifiers in classes.
    (Data hiding: a language feature to restrict access to members of an object, reducing the negative effect due to dependencies. e.g. "protected", "private" feature in Java). 

    Abstraction:
    We try to obtain an abstract view, model or structure of a real life problem, and reduce its unnecessary details. With definition of properties of problems, including the data which are affected and the operations which are identified, the model abstracted from problems can be a standard solution to this type of problems. It is an efficient way since there are nebulous real-life problems that have similar properties. 
    In simple terms, it is hiding the unnecessary details & showing only the essential parts/functionalities to the user.

    Abstraction is achieved in 2 ways : 1.Abstract class, 2.Interfaces (Pure Abstraction)
    --> Abstract-> extends, Interface-> impliments.

    Abstract class properties: 
    1.An abstract class must be declared with an abstract keyword.
    2.It can have abstract and non-abstract methods.
    3.It cannot be instantiated.
    4.It can have constructors and static methods also.
    5.It can have final methods which will force the subclass not to change the body of the method. Final method is unchangeable outside the main final method.

    Interfaces properties:
    1.All the fields in interfaces are public, static and final by default.
    2.All methods are public & abstract by default.
    3.A class that implements an interface must implement all the methods declared in the interface.
    4.Interfaces support the functionality of multiple inheritance. In java normally classes can't do multiple inheritance.

    // --> Data hiding is the process of protecting members of class from unintended changes whereas, abstraction is hiding the implementation details and showing only important/useful parts to the user.

*/

abstract class Animal{ // Abstract class
    Animal(){
        System.out.println("Animal constructor");
    }
    abstract void walk(); // Abstract method or function
    /*
        We first created walk function as,
        public void walk(){
        }
        Here we just used Animal class and walk function as a bluprint for Hourse and Chicken . Here Animal has no real uses so we can hide it from user by declaring it abstract
    */
    public void eats(){
        System.out.println("Animal eats");
    }
}

class  Hourse extends Animal{
    Hourse(){ // When Hourse inherites from Animal first Animal's constructor called then Hourse's constructor called ,it's called constructor chaining
        System.out.println("Hourse constructor");
    }
    public void walk(){
        System.out.println("Hourse walks on 4 legs");
    }
}

class Chicken extends Animal{
    Chicken(){
        System.out.println("Chicken constructor");
    }
    public void walk(){
        System.out.println("Chicken walks on 2 legs");
    }
}

    // // // //

interface  Bird {
    /*public*/ void fly(); // public doesn't need for interfaces but inherited class should always specify public first

    int eyes = 2; // It will be same for all Birds it can't be changed.
    // void eat(){
    //     System.out.println("Bird eats"); //-- error: interface abstract methods cannot have body
    // }
    // Bird(){
    //     System.out.println("Bird constructor"); //-- error: interface cannot have constructors
    // }
}

interface TwoWings{

}

class Crow implements Bird,TwoWings{ // Inherited from both Bird and TwoWings
    public void fly(){
        System.out.println("Crow flies in the sky");
    }
}

class Ostrich implements Bird,TwoWings{
    public void fly(){
        System.out.println("Ostrich walks on two legs and doesn't fly");
    }
}
public class OOP_5 {
    public static void main(String[] args) {
        Hourse h1 = new Hourse();
        h1.walk();
        h1.eats(); // Hourse doesn't have the eats function but Hourse inherites Animal class so it can call Animal's eats function

        Chicken c1 = new Chicken();
        c1.walk();

        // Animal a1 = new Animal();
        // a1.walk(); //--  error: Animal is abstract; cannot be instantiated (it's a runtime error)

        Crow cr1 = new Crow();
        cr1.fly();

        Ostrich o1 = new Ostrich();
        o1.fly();
    }
}

/*
    Constructor : Constructor is a special method which is invoked automatically at the time of object creation. It is used to initialize the data members of new objects generally. 
    1. Constructors have the same name as class or structure.
    2. Constructors don’t have a return type. (Not even void)
    3. Constructors are only called once, at object creation.

    There can be three types of constructors in Java. 
    1. Non-Parameterized constructor : A constructor which has no argument is known as non-parameterized constructor(or no-argument constructor). It is invoked at the time of creating an object. If we don’t create one then it is created by default by Java.

    2. Parameterized constructor : A constructor that has parameters is known as a parameterized constructor. It is used to provide different values to distinct objects.

    3. Copy Constructor : A Copy constructor is an overloaded constructor used to declare and initialize an object from another object. There is only a user defined copy constructor in Java(C++ has a default one too).

    **Unlike languages like C++, Java has no Destructor. Instead, Java has an efficient  garbage collector that deallocates memory automatically.

 */

class Student {
    String name;
    int age;

   // Non-Parameterized constructor
    Student() {
        System.out.println("Non-Parameterized Constructor called");
    }

    // Parameterized constructor
    Student(String name, int age) {
        System.out.println("Parameterized Constructor called");
        this.name = name;
        this.age = age;
    }

    // Copy Constructor
    Student(Student s) {
        System.out.println("Copy Constructor called");
        this.name = s.name;
        this.age = s.age;
    }

    public void getInfo() {
        System.out.println("The name of this Student is " + this.name);
        System.out.println("The age of this Student is " + this.age);
    }

}

public class OOP_2 {
    public static void main(String args[]) {

        Student s1 = new Student(); // Non-Parameterized constructor called
        s1.name = "Aman";
        s1.age = 24;
        s1.getInfo();

        System.out.println("");

        Student s2 = new Student("Shradha", 22); // Parameterized constructor called
        s2.getInfo();

        System.out.println("");

        Student s3 = new Student(s2); // Copy Constructor called
        s3.getInfo();
    }
}

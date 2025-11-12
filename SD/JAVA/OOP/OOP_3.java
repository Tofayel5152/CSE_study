/*
    Polymorphism:
    Polymorphism is the ability to present the same interface for differing underlying forms (data types). With polymorphism, each of these classes will have different underlying data. Precisely, Poly means ‘many’ and morphism means ‘forms’. 
    Types of Polymorphism:
    1. Compile Time Polymorphism (Static) 
    2. Runtime Polymorphism (Dynamic) 

    * Compile Time Polymorphism : The polymorphism which is implemented at the compile time is known as compile-time polymorphism. Example - Method Overloading.
    Method Overloading : Method overloading is a technique which allows you to have more than one function with the same function name but with different functionality. Method overloading can be possible on the following basis: 
    1. The type of the parameters passed to the function. 
    2. The number of parameters passed to the function.

    * Runtime Polymorphism : Runtime polymorphism is also known as dynamic polymorphism. Function overriding is an example of runtime polymorphism.
    Function overriding means when the child class contains the method which is already present in the parent class. Hence, the child class overrides the method of the parent class. In case of function overriding, parent and child classes both contain the same function with a different definition. The call to the function is determined at runtime is known as runtime polymorphism.

*/
/*
    Inheritance:
    Inheritance is a process in which one object acquires all the properties and behaviors of its parent object automatically. In such a way, you can reuse, extend or modify the attributes and behaviors which are defined in other classes. 
    In Java, the class which inherits the members of another class is called derived class and the class whose members are inherited is called base class. The derived class is the specialized class for the base class. 

    Types of Inheritance : 
    1. Single inheritance : When one class inherits another class, it is known as single level inheritance. Example: From the below example, Shape is the base class and Triangle is the derived class.(Excluding the circle class for this example)
    2. Hierarchical inheritance : Hierarchical inheritance is defined as the process of deriving more than one class from a base class. Example: From the below example, Shape is the base class and Triangle and Circle are the derived classes.
    3. Multilevel inheritance : Multilevel inheritance is a process of deriving a class from another derived class. Example: From the below example, Shape is the base class, Triangle is the derived class and EquilateralTriangle is the derived class of Triangle.
    4. Hybrid inheritance : Hybrid inheritance is a combination of simple, multiple inheritance and hierarchical inheritance. 

 */

    // Example of Compile Time Polymorphism (Method Overloading)
class Student {
    String name;
    int age;
        
    public void displayInfo(String name) { // Method Overloading
        System.out.println(name);
    }

    public void displayInfo(int age) { // Method Overloading
        System.out.println(age);
    }

    public void displayInfo(String name, int age) { // Method Overloading
        System.out.println(name);
        System.out.println(age);
    }
}

    // Example of Runtime Polymorphism (Method Overriding) and Inheritance
class Shape {
    public void area() {
        System.out.println("Displays Area of Shape ");
    }
}

class Triangle extends Shape { // Inheritance
    public void area(int h, int b) { // Method Overriding
        System.out.println("Triangle " + (0.5)*b*h);
    }  
}

class EquilateralTriangle extends Triangle { // Inheritance
    int side;
    public void area() { // Method Overriding
        System.out.println("Equilateral Triangle " + (Math.sqrt(3)/4)*side*side);
    }
}

class Circle extends Shape { // Inheritance
    public void area(int r) { // Method Overriding
        System.out.println("Circle " + (3.14)*r*r);
    }  
}

public class OOP_3 {
    public static void main(String[] args) {
        // Compile Time Polymorphism
        Student s1 = new Student();
        s1.displayInfo("Aman");
        s1.displayInfo(24);
        s1.displayInfo("Shradha", 22);

        System.out.println("");

        // Runtime Polymorphism
        Shape sh = new Shape();
        sh.area(); // Calls the method of base class

        Triangle t = new Triangle();
        t.area(10, 5);

        sh = new Circle();
        ((Circle) sh).area(7); // Downcasting

        EquilateralTriangle et = new EquilateralTriangle();
        et.side = 6;
        et.area();
    }
}

/*
    Static Keyword:
    The static keyword is used to define class-level members or variables that preserve their value for the entire program. Static elements belong to the class/program instead of individual objects.Static members belong to the class or program itself, not to individual objects
    Static can be : 
    1.Variable (also known as a class variable) -> A static variable is created only once and its value is retained throughout the program’s lifecycle.

    2.Method (also known as a class method) -> A static method belongs to the class, not to the object. It can be called without creating an object and can access only static data members. A static method cannot access non-static variables or methods directly because it does not belong to any specific object. Static methods are resolved at compile time (method hiding), so they cannot be overridden.
    Uses: For utility functions, To avoid creating unnecessary objects, For memory efficiency.

    3.Block -> A static block is used to initialize static variables. It executes once when the class is loaded.

    4.Nested class -> A static nested class does NOT need an outer class object. It can access only static members of the outer class. It behaves like a normal top-level class inside another class.

*/

class Student {
    String name;
    static String school; // school is same for all student that's why we can define it as static
    
}
public class OOP_6 {
    public static void main(String[] args) {
        Student.school = "IIUC"; // For static variables we don't need to create object , we can call veriables by "class name.veriables" 
        // Student.name = "Aks"; //-- Showing Error normally what happens, usually we need to create object to access class veriables

        Student Student = new Student();
        Student.name = "Aks";
        System.out.println("School: " + Student.school + ", Class: " + Student.name);
    }
}

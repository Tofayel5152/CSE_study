/*
    Package in Java:
    Package is a namespace that organizes a set of related classes and interfaces. Conceptually you can think of packages as being similar to different folders on your computer. Just as you might keep your documents organized within different folders, Java uses packages to keep related classes and interfaces together. 
    Package is a group of similar types of classes, interfaces and sub-packages. Packages can be built-in or user defined.
    Types of Packages:
    Built-in packages - java, util, io etc.(like these-> import java.util.Scanner;import java.io.IOException;)
    User-defined packages - We can create our own packages to organize our classes and interfaces.(Like this-> package other.tools; here the java program(Calc.java,AdvCalc,java) is saved in tools folder and tools saved in other folder. Like this we also created A.java program that saved in other folder. 
    We can import those files by calling import other.A; -> imports A.java , import other.tools.*; -> imports all java files in tools.Example is given in CODES folder.)


    // Access modifiers: 4 types(Example in CODES folder)
    1. Public: The access level of a public modifier is everywhere. It can be accessed from within the class, outside the class, within the package and outside the package.
    2. Protected: The access level of a protected modifier is within the package and outside the package through child class. If you do not make the child class, it cannot be accessed from outside the package.
    3. Private: The access level of a private modifier is only within the class. It cannot be accessed from outside the class.
    4. Default: The access level of a default modifier is only within the package. It cannot be accessed from outside the package. If you do not specify any access level, it will be the default.

 */

import java.util.*;
// import other.tools.*; // Usually get access to the Calc and AdvCalc file stored in other/tools folder location but here it doesn't get access cz the Calc,AdvCalc are in CODES file and OOP_4 is outside COEDS (Demo is inside thats why he gets access)

public class OOP_4 {
    public static void main(String[] args) {

        //Calc obj = new Calc();
        //System.out.println(obj.add(5, 10)); Won't work as this file doesn't get access.

        //  We used Built-in package like import java.util.*; to use Scanner class of util package.
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String st = sc.nextLine();

        System.out.println(st);



    }
}

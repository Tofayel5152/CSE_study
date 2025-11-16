
public class B {
    int marks = 100; // Defult type can't be accessed outside the CODES package so Demo.java can access it.
    private int mark; // Can nly be accessed in same class

    // But private variables can be accessed by setter & getter method by declaring them public.
    public int getMark(){
        return this.mark;
    }

    public void setMark(int mark){
        this.mark = mark;
    }

}

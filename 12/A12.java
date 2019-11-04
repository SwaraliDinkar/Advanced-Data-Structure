/*
Name:-Shubham Maheshwari
Roll Number-2274
Division-SE-II
Problem Statement:-
Write a program on template and exception handling in Java: in this assignment multiple templates are to be 
designed as a pattern and these patterns to be used to take decisions.
*/

import java.util.Stack;
abstract class MyStack{
    public final void pushTemplateMethod(){
        show();
        push();
        display();
    }
abstract protected void push();
abstract protected void display();
protected void show(){
    System.out.println("Stack implementation");
}
}

class IntStack extends MyStack{
    Stack <Integer> s= new Stack<Integer>();
    protected void push(){
        s.push(10);
        s.push(20);
       s.push(30);
    }
protected void display(){
  try
  {
    while(true)
    {
    if(s.isEmpty())
    {
     Throwable T=new Throwable("Stack Empty");
       throw(T);
       }
        System.out.println(s.pop());
    }
    }
    catch(Throwable T)
    {
      System.out.println("Exception :"+T);
    }
    }
}
class FloatStack extends MyStack{
    Stack<Float> s= new Stack<Float>();
    protected void push(){
        s.push(10.10f);
        s.push(20.20f);
       s.push(30.30f);
    }
protected void display(){
  try
  {
    while(true)
    {
    if(s.isEmpty())
    {
     Throwable T=new Throwable("Stack Empty");
       throw(T);
       }
        System.out.println(s.pop());
    }
    }
    catch(Throwable T)
    {
      System.out.println("Exception :"+T);
    }
    }
}
public class A12 {
     public static void main(String[] args){
         IntStack obj=new IntStack();
         obj.pushTemplateMethod();
         FloatStack obj1=new FloatStack();
         obj1.pushTemplateMethod();
     }
}

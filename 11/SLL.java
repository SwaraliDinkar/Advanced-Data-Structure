/*
Name:-Shubham Maheshwari
Roll Number-2274
Division-SE-II
Problem Statement:-
Write a Java program which will demonstrate a concept of Interfaces and packages: In this assignment design 
and use of customized interfaces and packages for a specific application are expected.
*/

import Assign11P2.*;
import java.util.Scanner;
class Node
{
  public Node next;
  public int data;
  public Node()
  {
    data=0;
    next=null;
  }
}
public class SLL implements SLL1
{
  Node start,tail;
  int size;
  Scanner Sc1=new Scanner(System.in);
  public static void main(String[] args)
   {
    int o;
    SLL L=new SLL();
    Scanner Sc=new Scanner(System.in);
    do
    {
      System.out.println("Enter choice.\n1.Insert.\n2.Delete head.\n3.Display.\n4.Display size.\n5.Exit.");
      o=Sc.nextInt();
      switch(o)
      {
        case 1:L.insert();
        break;
        
        case 2:L.deleteHead();
        break;
        
        case 3:L.display();
        break;
        
        case 4:System.out.println("Size: "+L.size);
        break;
        
        case 5:break;
        
        default: System.out.println("Enter valid option.");
        
      }
    }while(o!=5);
   
  }
 public void insert(){
    Node n=new Node();
    System.out.println("Enter integer.");
   n.data= Sc1.nextInt();
    if(start==null)
      start=tail=n;
     else
     {
       tail.next=n;
       tail=n;
     }
     size++;
  }
 public void deleteHead()
  {
    if(start==null)
    return;
    else
    start=start.next;
    size--;
    System.out.println("Deleted.");
  }
public  int showSize()
  {
    return(size);
  }
public  void display()
  {
   for(Node ptr=start;ptr!=null;ptr=ptr.next)
        System.out.print(ptr.data+"  ");
     System.out.println();
    
  }
  SLL()
  {
    start=tail=null;
    size=0;
  }
}

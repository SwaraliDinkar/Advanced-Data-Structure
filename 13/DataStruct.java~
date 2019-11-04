/*
Name:-Shubham Maheshwari
Roll Number-2274
Division-SE-II
Problem Statement:-
Write a Java program for the implementation of different data structures using JAVA collection libraries 
(Standard toolkit library): at least 5 data structures are used to design a suitable application.
*/


import java.util.*;

class Word
{
  public String w,m;
  public void get()
  {
    Scanner Sc1=new Scanner(System.in);
    String s1,s2;
    System.out.println("Enter word.");
    s1=Sc1.next();
    w=s1;
    System.out.println("Enter meaning");
    s2=Sc1.next();
    m=s2;
  }
  public void display()
  {
    System.out.println(w+"  "+m);
  }
}

public class DataStruct 
{
    Stack<Word> S;
   PriorityQueue<Word> Q;
    Vector<Word> V;
    LinkedList<Word> L;
    HashMap<String,String> H;
    static Scanner Sc=new Scanner(System.in);
  public static void main(String[] args)
   { 
    DataStruct D=new DataStruct();
    int choice;
  do
  {
    System.out.println("Enter choice\n1.Stack.\n2.Priority Queue.\n3.Vector.\n4.LinkedList.\n5.Hashmap.\n6.Exit");
     choice=Sc.nextInt();
     switch(choice)
     {
       case 1:D.stackOp();
       break;
       
       case 2:D.qOp();
       break;
       
       case 3:D.vectorOp();
       break;
       
       case 4:D.listOp();
       break;
       
       case 5:D.mapOp();
       break;
       
       case 6:break;
       
       default:System.out.println("Enter valid choice.");
     }
   }while(choice!=6);
  }
  void stackOp()
  {
    S=new Stack<>();
    Word A=new Word();
    int o;
    do
    {
      System.out.println("Enter choice.\n1.Push a word.\n2.Pop a word.\n3.Display top.\n4.Exit.");
      o=Sc.nextInt();
      switch(o)
      {
        case 1:A.get();
        S.push(A);
        break;
        
        case 2:A= S.pop();
        System.out.println("Popped.");
        break;
        
        case 3:A= S.peek();
        A.display();
        break;
        
        case 4:break;
        
        
      }
    }while(o!=4);
  }
  void qOp()
  {
    Q=new PriorityQueue<>();
    Word A=new Word();
    int o;
    do
    {
      System.out.println("Enter choice.\n1.Add a word.\n2.Dequeue a word.\n3.Display front.\n4.Exit.");
      o=Sc.nextInt();
      switch(o)
      {
        case 1:A.get();
        Q.add(A);
        break;
        
        case 2:
        Q.remove();
        System.out.println("Dequeued.");
        break;
        
        case 3:A= Q.peek();
        A.display();
        break;
        
        case 4:break;
        
        
      }
    }while(o!=4);
  }
  void vectorOp()
  {
    V=new Vector<>();
    Word A=new Word();
    int o;
    do
    {
      System.out.println("Enter choice.\n1.Add a word.\n2.Display capacity.\n3.Display.\n4.Exit.");
      o=Sc.nextInt();
      switch(o)
      {
        case 1:A.get();
        V.addElement(A);
        break;
        
        case 2:
        System.out.println("Capacity ="+V.capacity());
        break;
        
        case 3:
        Enumeration E=V.elements();
        while(E.hasMoreElements())
        {
          ((Word)(E.nextElement())).display();
        }
        break;
        
        case 4:break;
        
        
      }
    }while(o!=4);
  }
  void listOp()
  {
    L=new LinkedList<>();
    Word A=new Word();
    int o;
    do
    {
      System.out.println("Enter choice.\n1.Add a word.\n2.Remove.\n3.Exit.");
      o=Sc.nextInt();
      switch(o)
      {
        case 1:A.get();
        L.add(A);
        break;
        
        case 2:L.remove();
        break;
        
        case 3:break;
        
        
      }
    }while(o!=3);
  }
  void mapOp()
  {
    H=new HashMap<>();
    Word A=new Word();
    String s1;
    int o;
    do
    {
      System.out.println("Enter choice.\n1.Add a word.\n2.Check if word is present.\n3.Display.\n4.Exit.");
      o=Sc.nextInt();
      switch(o)
      {
        case 1:A.get();
       H.put(A.w,A.m);
        break;
        
        case 2:System.out.println("Enter word");
        s1=Sc.next();
        if(H.containsKey(s1))
        System.out.println("Present.");
        else
        System.out.println("Absent.");
        break;
        
        case 3:for(Map.Entry m:H.entrySet())
        {
          System.out.println(m.getKey()+"   "+m.getValue());
        }
       
        break;
        
        case 4:break;
        
        
      }
    }while(o!=4);
  }
}

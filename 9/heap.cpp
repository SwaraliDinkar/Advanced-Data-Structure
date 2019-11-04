/*
Name:-Shubham Maheshwari
Roll Number-2274
Division-SE-II
Problem Statement:-
Read the marks obtained by students of second year in an online examination of particular subject. 
Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the 
algorithm.
*/

#include<iostream>
using namespace std;
class heap
{
  int *a;
  int n;
  public:
  int p;
  void insert();
  void adjust_min(int);
  void adjust_max(int);
};
 	void heap::insert()
 	{
 	  if(p==3)
 	  {
 	    exit(1);	
	  }
	  cout<<"Enter total students: ";
 	  cin>>n;
 	  a=new int[n];
 	  for(int i=0;i<n;i++)
 	  {
 	    cout<<"Enter the marks: ";
 	    cin>>a[i];
 	    if(p==1)
 	    {
 	      adjust_min(i);
 	    }
 	    else if(p==2)
 	    {
 	      adjust_max(i);
 	    } 
 	  }
 	  if(p==1)
 	   cout<<"Minimum   marks: "<<a[0]<<endl;
 	  else if(p==2)
 	   cout<<"Maximum   marks: "<<a[0]<<endl;
 	}
 	void heap::adjust_min(int x)
 	{
 	  int temp;
 	  while(x>0 && a[(x-1)/2]>a[x])
 	  {
 	    temp=a[(x-1)/2];
 	    a[(x-1)/2]=a[x];
 	    a[x]=temp;
 	    x=(x-1)/2;
 	  }
 	}
 	void heap::adjust_max(int x)
 	{
 	  int temp;
 	  while(x>0 && a[(x-1)/2]<=a[x])
 	  {
 	    temp=a[(x-1)/2];
 	    a[(x-1)/2]=a[x];
 	    a[x]=temp;
 	    x=(x-1)/2; 
 	  }
 	}

int main()
{
  heap h;
l:cout<<"1)Min Heap\n2)Max heap\n3)Exit\nEnter your choice: ";
  cin>>h.p;
  h.insert();
  goto l;
  return 0;
}

/*
Name:-Shubham Maheshwari
Roll Number-2274
Division-SE-II
Problem Statement:-
Implement all the functions of a dictionary (ADT) using hashing. Data:  Set of (key, value) pairs, Keys are mapped 
to values,Keys must be comparable, Keys must be unique Standard Operations:  Insert(key, value), Find(key), Delete(key). 
(use linear probing with replacement and without replacement)*/

#include <iostream>
#define MAX 100
using namespace std;
class node
{
  string w;
  string m;
  node *next;
  public:
    friend class hashdict;
};
class hashdict
{
  public:
     node *dict[MAX];
     int key,key1,key2,key3;
	 hashdict()
	 {
	 	for(int i=0;i<MAX;i++)
	 	{
	 	   dict[i]=NULL;	
		}
	 }
	 void insert_without_replacement();	
	 void insert_with_replacement();
	 void find_word();
	 void del_word();
	 void print();
};
void hashdict::insert_without_replacement()
{
	int f=0;
	for(int i=0;i<MAX;i++)
	{
		if(dict[i]!=NULL)
		{
			f++;
		}
	}
	if(f==MAX-1)
	{
		cout<<"Dictionary is Full.\n";
		return;
	}
	string x,y;
	cout<<"Enter the word:-\n";
	cin>>x;
	cout<<"Enter the meaning:-\n";
	cin>>y;
	key=0;
	std::string::iterator j;
	for(j=x.begin();j!=x.end();j++)
	{
		key=key+(int)*j;
	}
	int k1,k2;
	k1=key%MAX;
	if(k1 > 99)
	{
		cout<<"!!Word Can't Be Inserted!!\n";
		return;
	}
	if(dict[k1]==NULL)
	{
		dict[k1]=new node;
		dict[k1]->w=x;
		dict[k1]->m=y;
		dict[k1]->next=dict[k1];
	}
	else
	{
		for(int i=k1;i<MAX;i=(i+1)%MAX)
		{
			if(dict[i]==NULL)
			{
				k2=i;
				break;
			}
		}
		dict[k2]=new node;
		dict[k2]->w=x;
		dict[k2]->m=y;
		dict[k2]->next=dict[k2];
	}
}
void hashdict::insert_with_replacement()
{
	int f1=0;
	for(int i=0;i<MAX;i++)
	{
		if(dict[i]!=NULL)
		{
			f1++;
		}
	}
	if(f1==MAX-1)
	{
		cout<<"Dictionary is Full.\n";
		return;
	}
	string x1,y1,x2,y2;
	cout<<"Enter the word:-\n";
	cin>>x1;
	cout<<"Enter the meaning:-\n";
	cin>>y1;
	key1=0;
	std::string::iterator j1;
	for(j1=x1.begin();j1!=x1.end();j1++)
	{
		key1=key1+(int)*j1;
	}
	int k3,k4;
	k3=key1%MAX;
	if(k3 > 99)
	{
		cout<<"!!Word Can't Be Inserted!!\n";
		return;
	}
	if(dict[k3]==NULL)
	{
		dict[k3]=new node;
		dict[k3]->w=x1;
		dict[k3]->m=y1;
		dict[k3]->next=dict[k3];
	}
	else
	{
		for(int i=k3;i<MAX;i=(i+1)%MAX)
		{
			if(dict[i]==NULL)
			{
				k4=i;
				break;
			}
		}
		x2=dict[k3]->w;
		y2=dict[k3]->m;
		dict[k3]->w=x1;
		dict[k3]->m=y1;
		dict[k4]=new node;
		dict[k4]->w=x2;
		dict[k4]->m=y2;
		dict[k4]->next=dict[k4];
	}
}
void hashdict::find_word()
{
	string x3;
	cout<<"Enter the word to be searched:-\n";
	cin>>x3;
	key2=0;
    std::string::iterator j2;
	for(j2=x3.begin();j2!=x3.end();j2++)
	{
		key2=key2+(int)*j2;
	}
	int k5,k6;
	k5=key2%MAX;
	if(k5 > 99)
	{
		cout<<"Word Not Found.\n";
		return;
	}
	if(dict[k5]==NULL)
	{
		cout<<"Word Not Found.\n";
	}
	else
	{
	  if(x3.compare(dict[k5]->w)==0)
	  {
	  	cout<<"Word Found at location "<<k5<<"."<<endl;
	  }
	  else
	  {
	  	int flag=0;
	  	for(int i=k5+1;i<MAX;i=(i+1)%MAX)
	  	{
	  	  if(x3.compare(dict[i]->w)==0)
			{
			 	flag=1;
			 	k6=i;
			 	break;
			}	
		}
		if(flag)
		{
		  cout<<"Word Found at location "<<k6<<"."<<endl;	
		}
		else
		{
		  cout<<"Word Not Found.\n";	
		}
	  }
	}
}
void hashdict::del_word()
{
	string x4;
	cout<<"Enter the word to be deleted:-\n";
	cin>>x4;
	key3=0;
    std::string::iterator j3;
	for(j3=x4.begin();j3!=x4.end();j3++)
	{
		key3=key3+(int)*j3;
	}
	int k7,k8;
	k7=key3%MAX;
	if(k7 > 99)
	{
		cout<<"Word can't be deleted as it is not present in Dictionary.\n";
		return;
    }
	if(dict[k7]==NULL)
	{
	  cout<<"Word can't be deleted as it is not present in Dictionary.\n";
	}
	else
	{
	  if(x4.compare(dict[k7]->w)==0)
	  {
	  	delete dict[k7];
	  	dict[k7]=NULL;
	  	cout<<"Word Deleted Succesfully.\n";
	  }
	  else
	  {
	  	int flag=0;
	  	for(int i=k7+1;i<MAX;i=(i+1)%MAX)
	  	{
	  	  if(x4.compare(dict[i]->w)==0)
			{
			 	flag=1;
			 	k8=i;
			 	break;
			}	
		}
		if(flag)
		{
		  delete dict[k8];
		  dict[k8]=NULL;
		  cout<<"Word Deleted Succesfully.\n";
		}
		else
		{
		  cout<<"Word can't be deleted as it is not present in Dictionary.\n";	
		} 
	  }	
	}
}
void hashdict::print()
{
	cout<<"Index"<<"\t\t"<<"Word"<<"\t\t"<<"Meaning"<<endl;
	for(int i=0;i<MAX;i++)
	{
		if(dict[i]!=NULL)
		{
			cout<<i<<"\t\t"<<dict[i]->w<<"\t\t"<<dict[i]->m<<endl;
		}
	}
}
int main()
{
	hashdict d1,d2;
    int p1,p2,p3;
    do
    {
    	cout<<"Enter your Choice:-\n";
    	cout<<"1.Linear Probing With Replacement\n";
    	cout<<"2.Linear Probing Without Replacement\n";
    	cout<<"3.Exit\n";
    	cin>>p1;
    	switch(p1)
    	{
    		case 1:
    		    do
				{
				  cout<<"---MENU---\n";
				  cout<<"1.Insert\n";
				  cout<<"2.Find\n";
				  cout<<"3.Delete\n";
				  cout<<"4.Display\n";
				  cout<<"5.Exit\n";
				  cin>>p2;
				  switch(p2)
				  {
				  	case 1:
				  		d1.insert_with_replacement();
				  		break;
				  	case 2:
				  		d1.find_word();
				  		break;
				  	case 3:
				  		d1.del_word();
				  		break;
				  	case 4:
				  		d1.print();
				  		break;
				  	case 5:
				  		break;
				  	default:
				  		cout<<"!!Invalid Choice!!\n";
				  		break;
				  }
				}while(p2!=5);	
			break;
			case 2:
				do
				{
				  cout<<"---MENU---\n";
				  cout<<"1.Insert\n";
				  cout<<"2.Find\n";
				  cout<<"3.Delete\n";
				  cout<<"4.Display\n";
				  cout<<"5.Exit\n";
				  cin>>p3;
				  switch(p3)
				  {
				  	case 1:
				  		d2.insert_without_replacement();
				  		break;
				  	case 2:
				  		d2.find_word();
				  		break;
				  	case 3:
				  		d2.del_word();
				  		break;
				  	case 4:
				  		d2.print();
				  		break;
				  	case 5:
				  		break;
				  	default:
				  		cout<<"!!Invalid Choice!!\n";
				  		break;
				  }
				}while(p3!=5);
			break;
			case 3:
			break;
			default:
			cout<<"!!Invalid Choice!!\n";
			break;		
		}
	}while(p1!=3);
	return 0;
}

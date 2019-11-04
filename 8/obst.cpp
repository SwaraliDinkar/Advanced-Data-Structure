/*
Name:-Shubham Maheshwari
Roll Number-2274
Division-SE-II
Problem Statement:-
Given sequence k = k1 <k2 <   < kn of n sorted keys, with a search probability 
pi for each key ki.Build the Binary search tree that has the least search cost 
given the access probability for each key.
*/

#include <iostream>
using namespace std;
#define MAX 999
int n;
class node
{
 int data;
 node *left;
 node *right;
 public:
   friend class obst;
};
class obst
{
	public:
	int y,z;
	int sum;
	int *keys;
	node *root;
	float *freq;
	int cost_matrix[10][10],root_matrix[10][10];
	void read();
	void create();
	void display();
	void optimal_cost();
	void inorder(node *p);
	void preorder(node *q);
    void postorder(node *r);
	void add_f(int e,int f);
	obst()
	{
		root=NULL;
	}
};
void obst::add_f(int e,int f)
{
	int s=0;
	for(int i=e;i<=f;i++)
	{
		s+=freq[i];
	}
	sum=s;
}
void obst::inorder(struct node *p)
{
if(p!=NULL)
 {
 inorder(p->left);
 cout<<p->data<<"\t";
 inorder(p->right);
 }
}
void obst::preorder(struct node *q)
{
if(q!=NULL)
 {
 cout<<q->data<<"\t";
 preorder(q->left);
 preorder(q->right);
 }
}
void obst::postorder(struct node *r)
{
if(r!=NULL)
 {
 postorder(r->left);
 postorder(r->right);
 cout<<r->data<<"\t";
 }
}
void obst::display()
{
if(root==NULL)
{
cout<<"Tree is Empty \n";
}
else
{
cout<<"Inorder traversal is:-\n";
inorder(root);
cout<<"\n";
cout<<"Preorder traversal is:-\n";
preorder(root);
cout<<"\n";
cout<<"Postorder traversal is:-\n";
postorder(root);
cout<<"\n";
}
}
void obst::read()
{
	cout<<"Enter the number of keys:-\n";
	cin>>n;
	keys=new int[n];
    freq=new float[n];
	cout<<"Enter the keys in ascending order:-\n";
	for(int i=0;i<n;i++)
	{
		cin>>keys[i];
	}
	cout<<"Enter the search probablity with respect to each key:-\n";
	for(int i=0;i<n;i++)
	{
		cin>>freq[i];
	}
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cost_matrix[i][j]=0;
    		root_matrix[i][j]=0;
		}
	}
}
void obst::optimal_cost()
{
	cout<<"The cost of Optimal Binary Search Tree is:-\n";
	for(int i=0;i<n;i++)
         {
         cost_matrix[i][i]=freq[i];
         }
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<=n-l+1;i++)
		{
			int j=i+l-1;
			cost_matrix[i][j]=MAX;
			sum=0;
			add_f(i,j);
			for(int r=i;r<=j;r++)
			{
				int cst=sum+((r > i)? cost_matrix[i][r-1]:0) + ((r < j)? cost_matrix[r+1][j]:0);
				if(cst < cost_matrix[i][j])
				  {
				    cost_matrix[i][j]=cst;	
				    root_matrix[i][j]=keys[r];
				    y=r;
			      }
			}		    
		}
	}
	cout<<cost_matrix[0][n-1]<<endl;
	cout<<"The root of the tree is:-\n";
	cout<<root_matrix[0][n-1]<<endl;
}
void obst::create()
{
  node *p=new node;
  p->left=p->right=NULL;
  if(root==NULL)
  {
    p->data=root_matrix[0][n-1];
    root=p;
  }	
}
int main()
{
  obst t;
  t.read();
  int l;
  do
  {
  	cout<<"Enter your choice:-\n";
  	cout<<"1.Minimum Optimal Cost\n";
  	cout<<"2.Create Optimal BST   \n";
  	cout<<"3.Display Tree Traversal\n";
  	cout<<"4.Exit\n";
  	cin>>l;
  	switch(l)
  	{
  	 case 1:
	   t.optimal_cost();
	   break;
	 case 2:
	   break;
	 case 3:
	    t.display();
	   break;
	 case 4:
	 	break;
	 default:
	   cout<<"!!Invalid Choice!!\n";
	   break;	
	}
  }while(l!=4);
  return 0;
}


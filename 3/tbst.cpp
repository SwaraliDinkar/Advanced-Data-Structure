/*
Name:-Shubham Maheshwari
Roll Number-2274
Division-SE-II
Problem Statement:-	
Convert given binary tree into in-ordered and preordered threaded binary tree.
Analyze time and space  complexity of the algorithm.
*/

#include<iostream>
using namespace std;
class tnode
{
	tnode *left,*right;
	bool rt,lt;
	int data;
public:
	friend class tbt;
};
class tbt
{
	tnode *root;
	public:
	tnode* getroot(){return(root);}
	tbt(){root=NULL;}
	tnode* getnode();
	void insert();
	void inorder();
	void preorder();
	void del();
	void mostof(tnode*,tnode* &p,tnode* &t,bool,bool);
};
void tbt::mostof(tnode *r,tnode* &p,tnode* &t,bool b1,bool b2)
{
	if(b1)
		{
		p=r->right;
		t=r;
		}
	else
		{
		p=r->left;	
		t=r;
		}
		
	if(b2)
		for(;(p)->right!=NULL&&(p)->rt!=1;p=(p)->right)
			t=p;
	else
		for(;(p)->left!=NULL&&(p)->lt!=1;p=(p)->left)
			t=p;
}
	
		
			
void tbt::del()
{
	tnode *p=NULL,*q,*t=root;
	int key;
	cout<<"Enter value to be deleted."<<endl;
	cin>>key;
	while(t!=NULL)
	{
		if(t->data>key&&!t->lt)
		{
			p=t;
			t=t->left;
		}
		else if(t->data<key&&!t->rt)
		{
			p=t;
			t=t->right;
		}
		else if(t->data==key)
		{
			q=t;
			while((q->left!=NULL&&!q->lt)||(q->right!=NULL&&!q->rt))
			{
				
				if(t->left!=NULL&&!q->lt)
					mostof(t,q,p,0,1);
				else
					mostof(t,q,p,1,0);
				t->data=q->data;
				t=q;	
			}
			if(p!=NULL)
			{
				if(p->left==q)
				{
					p->left=q->left;
					p->lt=q->lt;
				}
				else
				{
					p->right=q->right;
					p->rt=q->rt;
				}
			}
			else
				root=NULL;
			delete q;
			
			return;
		}
	}
	cout<<"Not found. Cannot delete."<<endl;
}			

tnode*  tbt::getnode()
{
	tnode *n=new tnode;
	cout<<"Enter data."<<endl;
	cin>>n->data;
	n->lt=n->rt=0;
	n->left=n->right=NULL;
	return(n);
}
void tbt::insert()
{
	bool re;
	do
	{
		tnode *q,*t=getnode();
		if(root==NULL)
		{
			root=t;
		}
		else
		{
			q=root;
			while(q!=NULL)
			{
				if(q->data==t->data)
				{
					cout<<"Already present. Can not enter again."<<endl;
					break;
				}
				if(q->data>t->data)
				{
					if(!q->lt&&q->left!=NULL)
						q=q->left;
					else 
					{
						t->left=q->left;
						t->lt=q->lt;
						t->rt=1;
						q->lt=0;
						q->left=t;
						t->right=q;
						break;
					}
				}
				else
				{
					if(!q->rt&&q->right!=NULL)
						q=q->right;
					else
					{
						t->right=q->right;
						t->rt=q->rt;
						t->lt=1;
						q->rt=0;
						q->right=t;
						t->left=q;
						break;
					}
				}
			}
			}
			cout<<"If you want to enter another node, enter 1.Else enter 0."<<endl;
			cin>>re;
		}while(re);
}
void tbt::inorder()
{
	cout<<"Inorder traversal."<<endl;
	tnode *q=root;
	while(q!=NULL)
	{
		for(;(q->left!=NULL)&&(!q->lt);q=q->left);
		
		for(;q->rt;q=q->right)
		{
			cout<<q->data<<"\t";
		}
		cout<<q->data<<"\t";
		q=q->right;
	}
	cout<<endl;
}
void tbt::preorder()
{
	cout<<"Preorder traversal."<<endl;
	tnode *q=root;
	while(q!=NULL)
	{
		for(;(q->left!=NULL)&&(!q->lt);q=q->left)
			cout<<q->data<<"\t";
		cout<<q->data<<"\t";
		for(;q->rt;q=q->right);
		q=q->right;
	}
	cout<<endl;
}
int main()
{
	tbt tr;
	int op;
	
	do
	{
	cout<<"Select an option.\n1.Insert.\n2.Delete.\n3.Inorder traversal.\n4.Preorder traversal.\n5.Exit."<<endl;
	cin>>op;
	switch(op)
	{
		case 1:tr.insert();
				break;
				
		case 2:tr.del();
				break;
				
		case 3:tr.inorder();
				break;
				
		case 4:tr.preorder();
				break;
				
		case 5:break;
		
		default:cout<<"Enter valid option."<<endl;
		
	}
	}while(op!=5);
	
	
	return 0;
}

		

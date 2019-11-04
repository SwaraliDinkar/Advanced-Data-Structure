/*
Name:-Shubham Maheshwari
Roll Number-2274
Division-SE-II
Problem Statement:-
Given binary tree with n nodes, perform following operations on it:
1. Perform preorder and post order traversal
2. Create a mirror image of it
3. Find the height of tree
4. Copy this tree to another [operator=] 
5. Count number of leaves, number of internal nodes. 
6. Erase all nodes in a binary tree. 
(implement both recursive and non-recursive methods)
*/

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
class node
{
 int data;
 node *left;
 node *right;
 public:
   friend class binarytree;
};
class binarytree
{
 public:
 int leaf,inter;
 node *n,*root;
 binarytree()
 {
   n=root=NULL;
 }
 void preorder(node *q);
 void inorder(node *p);
 void display();
 void postorder(node *r);
 void create();
 void mirror();
 void height();
  int maxDepth(node *node);
 void nodes();
 void delbinarytree(node *k);
 void deltree();
 void nodecalculate(node *y); 
 void mirror(node *p3);
 void callmirror();
 void non_inorder();
 void non_preorder();
 void non_postorder();
 void display_nonrecursive();
 node* rt();
 node* assign(node *t8); 
 void operator=(binarytree a);
};
void binarytree::create()
{
 queue <node*> q;
 cout<<"Enter the root element of a tree:-\n";
 node *n= new node;
 cin>>n->data;
 n->left=n->right=NULL;
 root=n;
 q.push(root);
struct node *temp;
char c,l;
while(!q.empty())
 {
 temp=q.front();
 q.pop();
 cout<<"Do you want to add left child of "<<temp->data<<" (y/n):-\n";
 cin>>c;
 if(c=='Y' || c=='y')
   {
     struct node *t=new node;
     cout<<"Enter left child:-\n";
     cin>>t->data;
     t->left=t->right=NULL;
     temp->left=t;
     q.push(t);
   }
 cout<<"Do you want to add right child of "<<temp->data<<" (y/n) :-\n";
 cin>>l;
 if(l=='Y' || l=='y')
   {
     struct node *t1=new node;
     cout<<"Enter right child:-\n";
     cin>>t1->data;
     t1->left=t1->right=NULL;
     temp->right=t1;
     q.push(t1);
   }
 }
}
void binarytree::inorder(struct node *p)
{
if(p!=NULL)
 {
 inorder(p->left);
 cout<<p->data<<"\t";
 inorder(p->right);
 }
}
void binarytree::preorder(struct node *q)
{
if(q!=NULL)
 {
 cout<<q->data<<"\t";
 preorder(q->left);
 preorder(q->right);
 }
}
void binarytree::postorder(struct node *r)
{
if(r!=NULL)
 {
 postorder(r->left);
 postorder(r->right);
 cout<<r->data<<"\t";
 }
}
void binarytree::display()
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
void binarytree::non_inorder()
{
 stack <node*> s1;
 if(root)
   {
     node *y4=root;
     do
     {
     while(y4!=NULL)
      {
       s1.push(y4);
       y4=y4->left;
      }
     y4=s1.top();
     s1.pop();
     cout<<y4->data<<"\t";
     y4=y4->right;
     }while(!s1.empty()||y4!=NULL);
   }
}
void binarytree::non_preorder()
{
  stack <node*> s2;
 if(root)
   {
     node *y5=root;
     do
     {
     while(y5!=NULL)
      {
       cout<<y5->data<<"\t";
       s2.push(y5);
       y5=y5->left;
      }
     y5=s2.top();
     s2.pop();
     y5=y5->right;
     }while(!s2.empty()||y5!=NULL);
   }
}
void binarytree::non_postorder()
{
    node *y6=root;
    if (y6 == NULL) 
        return;
    stack <node*> s3,s4;
    s3.push(y6);
    struct node* y7;
    while(!s3.empty())
    {
        y7=s3.top();
        s3.pop();
        s4.push(y7);
        if (y7->left)
           s3.push(y7->left);
        if (y7->right)
            s3.push(y7->right);
    }
    while (!s4.empty())
    {
        y7=s4.top();
        s4.pop();
        cout<<y7->data<<"\t";
    }
}
void binarytree::display_nonrecursive()
{
if(root==NULL)
{
cout<<"Tree is Empty \n";
}
else
{
cout<<"Non Recursive Inorder traversal is:-\n";
non_inorder();
cout<<"\n";
cout<<"Non Recursive Preorder traversal is:-\n";
non_preorder();
cout<<"\n";
cout<<"Non recursive Postorder traversal is:-\n";
non_postorder();
cout<<"\n";
}
}
int binarytree::maxDepth(node* node) 
{
   if(node==NULL) 
      return 0;
   else
   {
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
       if(lDepth > rDepth) 
        return(lDepth+1);
       else 
        return(rDepth+1);
   }
}
void  binarytree::height()
{
cout<<"Height of Binary Tree is:-\n";
int height;
height=maxDepth(root);
cout<<height<<"\n";
}
void binarytree::delbinarytree(node *k)
{
if(k==NULL)
return ;
delbinarytree(k->left);
delbinarytree(k->right);
delete k;
}
void binarytree::deltree()
{
cout<<"Binary Tree deleted succesfully.\n";
delbinarytree(root);
root=NULL;
}
void binarytree::nodes()
{
 leaf=0;
 inter=0;
 cout<<"The leaf and intermediate nodes of tree are:-\n";
 nodecalculate(root);
 cout<<leaf<<" and "<<inter-1<<endl;
}
void binarytree::nodecalculate(struct node *y)
{
 if(y)
 {
  nodecalculate(y->left);
  nodecalculate(y->right);
  if(y->left== NULL && y->right==NULL)
    {
      leaf++;
    }
  else
    {
     inter++;
    }
 }
}
void binarytree::mirror(node *p3)
{
struct node *temp;
if(p3==NULL)
return;
else
 {
   mirror(p3->left);
   mirror(p3->right);
   temp=p3->left;
   p3->left=p3->right;
   p3->right=temp;
 }
}	
void binarytree::callmirror()
{
cout<<"---Mirror Image of Binary Tree---\n";
mirror(root);
display();
}
node* binarytree::rt()
{
 return (root);
}
void binarytree::operator=(binarytree a)
{
  root=assign(a.rt());
}
node* binarytree::assign(node *t8)
{
  if(t8!=NULL)
   {
     node *p8=new node; 
     p8->data=t8->data;
     p8->left=assign(t8->left);
     p8->right=assign(t8->right);
     return t8;
   }
  return NULL;
}
int main()
{
binarytree b1,b2;
int l;
b1.create();
do
{
  cout<<"Enter your choice:-\n";
  cout<<"1.Display Binary Tree using Recursive Tree Traversal\n";
  cout<<"2.Display Binary Tree using Non-Recursive Tree Taversal\n";
  cout<<"3.Display Height of Binary Tree\n";
  cout<<"4.Leaf & Intermediate Nodes of Binary Tree\n";
  cout<<"5.Delete the Binary Tree\n";
  cout<<"6.Copy the Binary Tree\n";
  cout<<"7.Mirror Image of Binary Tree\n";
  cout<<"8.Exit\n";
  cin>>l;
  switch(l)
  {
   case 1:
   b1.display();  
   break;
   case 2:
   b1.display_nonrecursive();
   break;
   case 3:
   b1.height();
   break;
   case 4:
   b1.nodes();
   break;
   case 5:
   b1.deltree();
   break;
   case 6:
   b2=b1;
   cout<<"------Copied Binary Tree------\n";
   b2.display();
   break;
   case 7:
   b1.callmirror();
   break;
   case 8:
   break;
   default:
   cout<<"Invalid Choice\n";
   break; 
   }	
}while(l!=8);
return 0;
}	

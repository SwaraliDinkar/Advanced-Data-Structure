/*
Name:-Shubham Maheshwari
Roll Number-2274
Division-SE-II
Problem Statement:-
A Dictionary stores keywords & its meanings.Provide facility for adding new keywords, deleting keywords, 
updating values of any entry, assign a given tree into another tree (=). Provide facility to display 
whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may 
require for finding any keyword.  Use Binary Search Tree for implementation.
*/

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
class node
{
    string meaning;
    string word;
    node *left,*right;
public:
    friend class dictionary;
};
class dictionary
{
public:
    node *root,*p;
    string a,b,c,d;
    int count,found;
    dictionary()
    {
        root=p=NULL;
    }
    void insertword();
    node* dic_search(string j);
    void delword();
    void updateword();
    void inorder_1(struct node *m);
    void inorder_2(struct node *n);
    void ascending_display();
    void descending_display();
    void comparisions();
    void searchword();
    node* rt();
    node* assign(node *t8); 
    void operator=(dictionary a);
};
void dictionary::insertword()
{
 int flag;
 string x,y;
 cout<<"Enter the word:-\n";
 cin>>x;
 cout<<"Enter the meaning:-\n";
 cin>>y;
 node *p=new node;
 p->right=p->left=NULL;
 p->word=x;
 p->meaning=y;
 if(root==NULL)
 {
     root=p;
    cout<<"Root is added.\n";
 }
 else
 {
     struct node *q=root;
     flag=0;
     while(flag!=1)
     {
         if(p->word < q->word)
         {
             if(q->left==NULL)
             {
                 q->left=p;
                 flag=1;
                 cout<<p->word<<" get added to left of "<<q->word<<".\n";
             }
             else
             {
                 q=q->left;
             }
         }
         else if(p->word > q->word)
         {
             if(q->right==NULL)
             {
                 q->right=p;
                 flag=1;
                 cout<<p->word<<" get added to right of "<<q->word<<".\n";
             }
             else
             {
                 q=q->right;
             }
         }
         else if(p->word == q->word)
         {
            cout<<"Word is already present in the dictionary.\n";
            return;
         }
     }
 }
}
void dictionary::inorder_1(struct node *m)
{
 if(m!=NULL)
 {
 inorder_1(m->left);
 cout<<m->word<<"\t";
 inorder_1(m->right);
 }
}
void dictionary::inorder_2(struct node *n)
{
 if(n!=NULL)
 {
 inorder_2(n->right);
 cout<<n->word<<"\t";
 inorder_2(n->left);
 }
}
void dictionary::ascending_display()
{
 if(root==NULL)
  {
  cout<<"Tree is Empty.\n";
  }
 else
  {
  cout<<"Displaying Words of Dictionary in ascending order:-\n";
  inorder_1(root);
  cout<<"\n";
  }
}
void dictionary::descending_display()
{
 if(root==NULL)
  {
  cout<<"Tree is Empty.\n";
  }
 else
  {
  cout<<"Displaying Words of Dictionary in descending order:-\n";
  inorder_2(root);
  cout<<"\n";
  }
}
node* dictionary::dic_search(string j)
{
    found=count=0;
    struct node *q1=root;
    while(found!=1)
    {
       count++;
       if(j < q1->word)
         {
             if(q1->left==NULL)
             {   
               return NULL;
             }
             else
             {
                q1=q1->left;
             }
         }
      else if(j > q1->word)
         {
             if(q1->right==NULL)
             {
               return NULL;
             }
             else
             {
                 q1=q1->right;
             }
         }
      else 
       {
          if((j.compare(q1->word))==0)
          {
               found=1;
               return q1;
          }
       }
    }
}
void dictionary::searchword()
{
 node *u;
 cout<<"Enter the word to be search:-\n";
 cin>>a;
 if(root==NULL)
  {
   cout<<"Dictionary is Empty.\n";
   return ;
  }
 u=dic_search(a);
 if(u==NULL)
    {
    cout<<"Word Not Found.\n";
    }
 else
    {
      cout<<"Word Found.\n";
      cout<<u->word<<"\t"<<u->meaning<<"\n";
    }      
}
void dictionary::updateword()
{
  cout<<"Enter the word to be updated:-\n";
  cin>>b;
  if(root==NULL)
   {
    cout<<"Dictionary is Empty.\n";
    return;
   }
  struct node *e;
  e=dic_search(b);
  if(e==NULL)
    {
    cout<<"Word Not Found.\n";
    }
 else
    {
      cout<<"Word Found.\n";
      cout<<"Enter the updated meaning:-\n";
      cin>>c;
      e->meaning=c;
    }            
}
void dictionary::comparisions()
{
 cout<<"The maximum comparisions required for searching are:-\n";
 cout<<count<<"\n";
}
void dictionary::delword()
{
  string k;
  cout<<"Enter the word which you want to delete:-\n";
  cin>>k;
  struct node *w;
  w=dic_search(k);
  if(w==NULL)
    {
    cout<<"Word can't be deleted as it is not present in te dictionary .\n";
    }
  else
  {
  struct node *q2=root;
  struct node *p2=root;
    while(1)
    {
       if(k < q2->word)
         {
           p2=q2;
           q2=q2->left;
         }
      else if(k > q2->word)
         {
           p2=q2;
           q2=q2->right;
         }
     else if(q2->left==NULL && q2->right==NULL)
      {
        if(p2->left==q2)
           {
             p2->left=NULL;
             delete q2;
             cout<<"Node deleted succesfully\n";
             return;
           }
        else
           {
             p2->right=NULL;
             delete q2;
             cout<<"Node deleted succesfully\n";
             return;
           }
      }
    else if(q2->left==NULL)
      {
        if(p2->right==q2)
          {
           p2->right=q2->right;
           delete q2;
           cout<<"Node deleted succesfully\n";
           return; 
          }
        else
          {
           p2->left=q2->right;
           delete q2;
            cout<<"Node deleted succesfully\n";
           return;
          }
      }
    else if(q2->right==NULL)
      {
          if(p2->right==q2)
          {
           p2->right=q2->left;
           delete q2;
            cout<<"Node deleted succesfully\n";
           return; 
          }
        else
          {
           p2->left=q2->left;
           delete q2;
            cout<<"Node deleted succesfully\n";	
           return;
          }
      }
    else if(q2->left!=NULL && q2->right!=NULL)
          {
            node *q3,*q4;
            q3=q2->right;
            q4=q2->right; 
            while(q3->left!=NULL)
                 {
                   q4=q3;
                   q3=q3->left;
                 }
            q2->word=q3->word;
            q2->meaning=q3->meaning;
            if(q3->left==NULL)
              {
                q2->right=q3->right;
                delete q3;
              }
	    else
               {
                q4->left=q3->right;
                delete q3;
               }
            cout<<"Node deleted succesfully\n";	
            return; 
          }
    }
 }
}
node* dictionary::rt()
{
 return (root);
}
void dictionary::operator=(dictionary a)
{
  root=assign(a.rt());
}
node*  dictionary::assign(node *t8)
{
  if(t8!=NULL)
   {
     node *p8=new node; 
     p8->word=t8->word;
     p8->meaning=t8->meaning;
     p8->left=assign(t8->left);
     p8->right=assign(t8->right);
     return t8;
   }
  return NULL;
}
int main()
{
dictionary d1,d2;
int l;
do
{
  cout<<"Enter your choice:-\n";
  cout<<"1.Insert a Word in the Dictionary\n";
  cout<<"2.Display Words of Dictionary in Ascending order\n";
  cout<<"3.Display Words of Dictionary in Descending order\n";
  cout<<"4.Search a Word in the Dictionary\n";
  cout<<"5.Delete a Word from the Dictionary\n";
  cout<<"6.Update a Word in the Dictionary\n";
  cout<<"7.Calculate Maximum Comparisons\n";
  cout<<"8.Copy the Dictionary word into another Dictionary\n";
  cout<<"9.Exit\n";
  cin>>l;
  switch(l)
  {
   case 1:
   d1.insertword();
   break;
   case 2:
   d1.ascending_display();
   break;
   case 3:
   d1.descending_display();
   break;
   case 4:
   d1.searchword();
   break;
   case 5:
   d1.delword();
   break;
   case 6:
   d1.updateword();
   break;
   case 7:
   d1.comparisions();
   break;
   case 8:
   d2=d1;
   cout<<"------Copied Dictionary------\n";
   cout<<"Ascending Order Display:-\n";
   d2.ascending_display();
   cout<<"Descending Order Display:-\n";
   d2.descending_display();
   break;
   case 9:
   break;
   default:
   cout<<"Invalid Choice\n";
   break;
  }
}while(l!=9);
return 0;
}

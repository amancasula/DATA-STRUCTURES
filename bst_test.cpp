#include<iostream>
using namespace std;
class node{
public:
int data;
node *left;
node *right;
node(int data1=0,node *left1=NULL,node *right1=NULL){
data1=data;
left=left1;
right=right1;
}
};

class tree{
public:
node *root=new node;
void insert(int x){
insert(x,root);
return;
}
void insert(int x,node *n){

if(n->data==0){
n->data=x;
n->left=NULL;
n->right=NULL;
cout<<"inserted";
return;
}
else if(n->data > x){
  if(n->left == NULL)
  {
   node *nu=new node;
   nu->data=x;
   n->left=nu;
   cout<<"inserted";
  }
  else if(n->left != NULL){
  insert(x,n->left);
  }
return;
}
else if(n->data < x){
  if(n->right == NULL)
  {
   node *nu=new node;
   nu->data=x;
   n->right=nu;
   cout<<"inserted";
  }
  else if(n->right != NULL){
  insert(x,n->right);
  }
return;
}
}
void inorder(){
inorder(root);
}
void inorder(node *n){
if(n==NULL)
{
return;
}
inorder(n->left);
cout<<n->data;
inorder(n->right);
}
void preorder(){
preorder(root);
}
void preorder(node *n){
if(n==NULL)
{
return;
}
cout<<n->data;
preorder(n->left);
preorder(n->right);
}
void postorder(){
postorder(root);
}
void postorder(node *n){
if(n==NULL)
{
return;
}
postorder(n->left);
postorder(n->right);
cout<<n->data;
}

void search(int x){
search(x,root);
return;
}
void search(int x,node *n){

if(n->data==0){
cout<<"tree is empty";
return;
}
else if(n->data==x){
cout<<"node is found";
return;
}
else if(n->data > x){
  if(n->left == NULL)
  {
   cout<<"node is not found";
  }
  else if(n->left != NULL){
  search(x,n->left);
  }

}
else if(n->data < x){
  if(n->right == NULL)
  {
   cout<<"node is not found";
  }
  else if(n->right != NULL){
  search(x,n->right);
  }

}
}
};








int main()
{
tree t;
while(1)
{
int s;
cout<<"\n\n1.insert \n2.inorder \n3.preorder \n4.postorder \n5.search \n6.exit";
cin>>s;
switch(s)
{
case 1:
int newno;
cout<<"enter no to be inserted";
cin>>newno;
t.insert(newno);
break;
case 2:
t.inorder();
break;
case 3:
t.preorder();
break;
case 4:
t.postorder();
break;
case 5:
int searchno;
cout<<"enter no to be searched";
cin>>searchno;
t.search(searchno);
break;
case 6:
return 0;
break;
default:
cout<<"enter valid option";
break;
}
}
}


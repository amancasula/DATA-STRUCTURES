#include<iostream>
using namespace std;
class node{
public:
int value;
node *next;
node(int num=0,node *next1=NULL)//:value(num) , next(next1)
{
value=num;
next=next1;
}
};
class A{
public:

node *start=new node;
node *temp=new node;

void add(int nu)
{

node *n=new node(nu,NULL);
if(start->next == NULL){  //empty list
start->next=n;
n->next=n;
cout<<"added";
return;
}
int resp1=0;             //after any element
cout<<"after which element do u want to add?";
cin>>resp1;
temp=start;
while(1){
if(temp->value == resp1){
break;
}
temp=temp->next;
}
n->next=temp->next;
temp->next=n;
cout<<"added";
return;
}
int disp()
{
if((*start).next==0)//or if(start->next==0)
{
cout<<"list is empty";
return 0;
}
temp=start->next;
while(1)
{
if(temp->next==start->next)
break;
cout<<temp->value<<"-->";
temp=temp->next;
}
cout<<temp->value<<"-----------[TOWARDS FIRST]---";
return 0;
}
void del()
{
if(start->next==0)
{
cout<<"list is empty";
return;
}
cout<<endl<<"which element do you want to delete?"; 
int resp4;
cin>>resp4;
if(resp4 == (start->next)->value && (start->next)->next == start->next){   //only 1 element
start->next=NULL;
cout<<"deleted";
return;
}
temp=start->next;                  //any element
while(1){
if((temp->next)->value == resp4){
break;
}
temp=temp->next;
}
if(temp->next == start->next){     //if first element
start->next=(temp->next)->next;
}
temp->next=(temp->next)->next;
cout<<"deleted";
return;
}
};
int main()
{
A o;
int v,number;
while(true)
{
cout<<endl;
cout<<"-------------------------------------"<<endl;
cout<<"1.add"<<endl<<"2.display"<<endl<<"3.delete"<<endl<<"4.exit"<<endl;
cin>>v;
switch(v)
{
case 1:cout<<"enter num";
       cin>>number;
       o.add(number);
       break;
case 2:o.disp();
       break;
case 3:o.del();
       break;
case 4:break;
default:cout<<"invalid";
        break;
}
if(v==4)
break;
}
return 0;
}



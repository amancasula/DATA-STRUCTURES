#include<iostream>
using namespace std;
class node{
public:
int value;
node *next;
node *prev;
node(int num=0, node *next1=NULL, node *prev1=NULL)//:value(num) , next(next1)
{
value=num;
next=next1;
prev=prev1;
}
};
class A{
public:


node *start=new node;
node *last=new node;
node *temp=new node;
A(){
start->next=last;
last->prev=start;
}

void add(int nu)
{
node *n=new node(nu,NULL);
cout<<endl<<"do you want to add at begenning?(y/n)"<<endl;
char resp;
cin>>resp;
if(resp=='y')
{
jumpline:
temp=start->next;
start->next=n;
n->prev=start;
n->next=temp;
temp->prev=n;
}
else if(resp=='n')
{
cout<<"do you want to add at last(y/n)?"<<endl;
char resp2;
cin>>resp2;
if(resp2=='y')
{
temp=last->prev;
last->prev=n;
n->next=last;
n->prev=temp;
temp->next=n;
}
else if(resp2=='n')
{
cout<<endl<<"after which element do you want to add?"<<endl;
int resp3;
cin>>resp3;
temp=start->next;
while(1)
{
if(temp->value==resp3)
break;
temp=temp->next;
}
n->next=temp->next;
n->prev=temp;
(temp->next)->prev=n;
temp->next=n;
}
}
cout<<"added";
}
int disp()
{
if((*start).next== last )//or if(start->next==0)
{
cout<<"list is empty";
return 0;
}
char resp5;
cout<<"forward traversal[f] or backward traversal[b]?";
cin>>resp5;
if (resp5=='f'){
cout<<"start<-->";
temp=start->next;
while(1)
{
if(temp->next==last)
break;
cout<<temp->value<<"<-->";
temp=temp->next;
}
cout<<temp->value<<"<-->last";
return 0;
}
else{
cout<<"last<-->";
temp=last->prev;
while(1)
{
if(temp->prev==start)
break;
cout<<temp->value<<"<-->";
temp=temp->prev;
}
cout<<temp->value<<"<-->start";
return 0;
}
}
void del()
{
if(start->next==last)
{
cout<<"list is empty";
return;
}
cout<<endl<<"which element do you want to delete?";
int resp4;
cin>>resp4;
temp=start->next;
while(1)
{
if(temp->value==resp4)
break;
temp=temp->next;
}
(temp->next)->prev=temp->prev;
(temp->prev)->next=temp->next;
cout<<"deleted";
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



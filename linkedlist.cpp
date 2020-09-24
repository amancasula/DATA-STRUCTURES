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
cout<<endl<<"do you want to add at begenning?(y/n)"<<endl;
char resp;
cin>>resp;
if(resp=='y')
{
jumpline:
temp=start->next;
start->next=n;
n->next=temp;
}
else if(resp=='n')
{
cout<<"do you want to add at last(y/n)?"<<endl;
char resp2;
cin>>resp2;
if(start->next==NULL)
{
goto jumpline;
}
if(resp2=='y')
{
temp=start->next;
while(1)
{
if(temp->next==NULL)
break;
temp=temp->next;
}
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
temp->next=n;
}
}
cout<<"added";
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
if(temp->next==NULL)
break;
cout<<temp->value<<"-->";
temp=temp->next;
}
cout<<temp->value<<"-->NULL";
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
temp=start->next;
if(temp->value==resp4)//for first case
{
start->next=temp->next;
cout<<"deleted";
return;
}
while(1)
{
if((temp->next)->value==resp4)
break;
temp=temp->next;
}
temp->next=(temp->next)->next;
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



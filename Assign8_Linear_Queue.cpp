#include<iostream>
#define SIZE 5
using namespace std;
class food_hills
{
public:
String name;
String order;
float bill;
food_hills *next;
food_hills()
{
next=NULL;
}
};
class food_ordering
{
food_hills *front,*rear;
public:
food_ordering()
{
front=NULL;
rear=NULL;
}
bool isEmpty()
{
if(front==NULL && rear==NULL)
return true;
else
return false;
}
void enqueue()
{
string order;
string mname;
cout<<"Enter the order:";
cin>>order;
cout<<"Enter the Name:";
cin>>mname;
food_hills *temp;
temp=new food_hills();
temp->order=order;
temp->name=mname;
if(isEmpty())
{
front=temp;
rear=temp;
}
else{
rear->next=temp;
rear=temp;
} }
void dequeue()
{
food_hills *temp;
if(!isEmpty())
{
if(front==rear)
{
cout<<"\nfood ordering is done"<<front-
>order<<":"<<front->name;
temp=front;
front=NULL;
rear=NULL;
delete(temp);
}
else
{
temp=front;
front=front->next;
delete(temp);
} }
else
cout<<"\n No customer is waiting in queue";
}
void display()
{
food_hills *p;
if(!isEmpty())
{
cout<<"\nFollowing customer waiting in queue for food ordering ";
p=front;
while(p!=NULL)
{
cout<<"\n"<<p->order<<"=="<<p->name;
p=p->next;
} } }
};
int main()
{ 
 food_ordering f;
 int t;
 do
 {
 int choice;
 
 
 cout<<"\n1.Enqueue \n2.Dequeue \n3.Display";
 cout<<"\nEnter the choice";
 cin>>choice;
 switch(choice)
 {
 case 1:
 int n;
 cout<<"Enter number of Enteries";
 cin>>n;
 for(int i=0;i<n;i++)
 {
 f.enqueue();
}
break;
case 2:
f.dequeue();
break;
case 3:
f.display();
break;
}cout<<"\nEnter 1 to continue";
cin>>t;
}
while(t==1);
}

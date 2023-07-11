#include<iostream>
using namespace std;
#define max 5
class shopping_mall
{
	public:
	string item;
	int quantity,price;
	void getdata()
{
	cout<<"\nEnter the Name of Item : ";
	 cin>>item;
	 cout<<"Enter the quantity : ";
	cin>>quantity;
	cout<<"Enter the price : ";
	cin>>price;
}
};
class dequeue
{
	public:
	shopping_mall data[max];
	int front,rear;
	dequeue()
{
	rear =-1;
	front =-1;
}
	bool isFull();
	bool isEmpty();
	void insert_front(shopping_mall s);
	void insert_rear(shopping_mall s);
	void delete_front();
	void delete_rear();
	void display();
};
	bool dequeue::isFull()
{
	if((front==0 && rear==max-1) || (front==rear+1))
	return true;
	else
	return false;
}
	bool dequeue::isEmpty()
{
	if(front==-1)
	return true;
	else
	return false;
}
	void dequeue::insert_front(shopping_mall s)
{
	if(isFull())
{
	cout<<"Dequeue is full"<<endl ;
}
else
{
	if(isEmpty())
{
	front = 0;
	rear =0;
}
else                                   //Insert at front means f--
{
	front=(front-1+max)%max;
}
	data[front].item = s.item;
	data[front].quantity =s.quantity;
	data[front].price =s.price;
}
}
void dequeue::insert_rear(shopping_mall s)
{
	if(isFull())
{
	cout<<"\n Dequeue is full \n"<<endl;
}
else if(front==-1)
{
	front =0;
	rear=0;
}
else                               //Insert at rear means r++
{
	rear=(rear+1)%max;
}
	data[rear].item = s.item;
	data[rear].quantity =s.quantity;
	data[rear].price =s.price;
}
void dequeue::delete_front()
{
if(isEmpty())
{
	cout<<"\nDequeue is empty"<<endl;
}
else if(front==rear)
{
	front=-1;
	rear=-1;
}
else                                      //Delete the front means f++
{
	front=(front+1+max)%max;
}
}
void dequeue::delete_rear()
{
if(isEmpty())
{
	cout<<"\nDequeue is empty"<<endl;
}
else if(front==rear)
{ 
	front=-1;
	rear=-1;
}
else                                                //Delete at rear means r--
{
rear=(rear-1+max)%max;
}
}
void dequeue::display()
{
int i=front;
cout<<"\n======== Operations for a shopping mall =========\n";
cout<<"\n-----------------------------------------------------\n";
cout<<"\n **** Shopping details **** \n\n" ;
if(isEmpty())
{
cout<<"\ndequeue is empty\n"<<endl;
}
else if(front<=rear)
{
for(int i =front; i<=rear;i++)
{
cout<<"\n=========================";
cout<<"\n\t\tItem : "<<data[i].item ;
cout<<"\n\t\tQuantity : "<<data[i].quantity ;
cout<<"\n\t\tPrice : "<<data[i].price<<"" ;
cout<<"\n=========================";
}
}
else
{
while(i<=max-1)
{
cout<<"\n=========================";
cout<<"\n\t\tItem : "<<data[i].item ;
cout<<"\n\t\tQuantity : "<<data[i].quantity ;
cout<<"\n\t\tPrice : "<<data[i].price<<"" ;
cout<<"\n=========================";
i++;
}
i=0;
while(i<=rear)
{
cout<<"\n=========================";
cout<<"\n\t\tItem : "<<data[i].item ;
cout<<"\n\t\tQuantity : "<<data[i].quantity ;
cout<<"\n\t\tPrice : "<<data[i].price<<"" ;
cout<<"\n=========================";
i++;
}
}
}
int main()
{
shopping_mall sm;
dequeue d;
int c;
do 
{
cout<<"\n\n\n********* Operations for a shopping mall *********\n";
cout<<"\n1.insert at front \n2.insert at rear \n3.display";
cout<<"\n4.delete from front \n5.delete from rear \n6.exit\n";
cout<<"\n-----------------------------------------------------\n";
 cout<<"\n\nEnter your choice : ";
 cin>>c;
 
 switch(c)
 {
 case 1 :
 sm.getdata();
 d.insert_front(sm);
 break;
 
 case 2 :
 sm.getdata();
d.insert_rear(sm);
break;
 
case 3 : 
d.display();
break;

case 4 : 
d.delete_front();
break;

case 5 :
d.delete_rear();
break;

case 6 :
break;

default : cout<<"\ninvalid choice\n"<<endl;
 
 } 
} 
while(c!=6) ;
return 0 ;
}

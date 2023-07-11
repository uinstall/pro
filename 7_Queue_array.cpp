#include <iostream>
#define MAX 5
using namespace std;
class food_hills
{
	string name;
	string order;
	int q[MAX],rear,front;
	public:
	void add();
	void del();
	int isFull();
	int isEmpty();
	int get_rear();
	int get_front();
	void display();
	food_hills()
{
	rear=-1;
	front=-1;
}
};
void food_hills::add()
{
	int enteries;
	if(isFull()==1)
{
cout<<"Queue is full";
}
else
if(rear==MAX)
{
rear=0;
}
if(rear==-1)
{
rear=0;
}
	cout<<"\n====== Enter number of Enteries: =======";
	cin>>enteries;
	q[rear]=enteries;
	rear=rear+1;
}
void food_hills::del()
{
if(isEmpty()==1)
	cout<<"Queue is empty";
else
{
	if(front==MAX)
	front=0;
	if(front==-1)
	front=0;
	cout<<q[front]<<"is del";
	front=front+1;
}
}
int food_hills::isEmpty()
{
	if(rear==-1 || front==rear)
	return 1;
	return 0;
}
int food_hills::isFull()
{
	if(rear==MAX && front==rear)
	return 1;
	return 0;
}
int food_hills::get_rear()
{
	if(isEmpty()!=1)
	return(q[rear-1]);
	return -1;
}
int food_hills::get_front()
{
	if(isEmpty()!=1)
	return(q[front-1]);
	return -1;
}
void food_hills::display()
{
	int i;
	if(isEmpty()==1)
	cout<<"Empty";
else
{
	cout<<"Queue=";
	if(front==-1)
	front=0;
	for(int i=front;i<rear;i++)
	cout<<q[i]<<"\t";
}
}
int main()
{
	food_hills f;
	int ch,t;
	do
{
	int choice;
	cout<<"========= Select the operation to be performed =========";
	cout<<"\n1.Add\n2.Delete\n3.isFull\n4.isEmpty\n5.get_Rear\n6.get_Front\n7.Display\n8.Exit";
	cout<<"\nEnter the choice :";
	cin>>ch;
switch(ch)
{
	case 1:int enteries;
	cout<<"\nEnter enteries";
	cin>>enteries;
	f.add();
	break;
	
	case 2:
	f.del();
	break;
	
	case 3:
	f.isFull();
	break;
	
	case 4:
	f.isEmpty();
	break;
	
	case 5:
	f.get_rear();
	break;
	
	case 6:
	f.get_front();
	
	case 7:
	f.display();
	
	case 8:
	exit(0);
}
	cout<<"\nEnter 1 to continue";
	cin>>t;
}
	while(t==1);
}

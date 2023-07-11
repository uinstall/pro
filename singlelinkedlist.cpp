#include<iostream>
 using namespace std;
 class node
 {
 public:
 int rno;
 string name;
 float cgpa;
 class node *next;
 };
 class SLL
 {
 node *head;
 public:
 SLL()
 {
 head=NULL;
 }
 void create();
 void display();
 void insert();
 void delet();
 void sort();
 void search();
 };
 void SLL::create()
 {
 int ch;
 node *newnode,*temp;
 do{newnode=new node;
 cout<<"Enter Student Data \n"<<endl;
 cout<<"Enter Roll No"<<endl;
cin>>newnode->rno;
 cout<<"Enter Name"<<endl;
 cin>>newnode->name;
 cout<<"Enter CGPA"<<endl;
 cin>>newnode->cgpa;
 newnode->next=NULL;
 if(head==NULL)
 {
 head=newnode;
 }
 else{
temp=head;
 while(temp->next!=NULL)
 {
temp=temp->next;
 }
 temp->next=newnode;
 }
 cout<<"\nPress 1 to continue or 0 to close";
 cin>>ch;
 }
 while(ch==1);
}
 void SLL::insert()
{
 node *newnode,*temp;
 int ch,d,flag=0;
 cout<<"\n=== Enter the choice ==="<<endl;
 cout<<"\n1.At Start \n 2.In Between \n 3.At Last"<<endl;
 cin>>ch;
 if(ch==1)
 {
 newnode=new node;
 cout<<"\nEnter New Student Data"<<endl;
 cout<<"Enter Roll No"<<endl;
 cin>>newnode->rno;
 cout<<"Enter Name"<<endl;
 cin>>newnode->name;
cout<<"Enter CGPA"<<endl;
 cin>>newnode->cgpa;
 newnode->next=head;
 head=newnode;
 }
 if(ch==2)
 {
 cout<<"\nEnter node after which you want to enter"<<endl;
 cin>>d;
 temp=head;
 while(temp!=NULL)
 {
 if(temp->rno==d)
 {
 cout<<"Node found"<<endl;
 newnode=new node;
 cout<<"\nEnter New Student Data"<<endl;
 cout<<"Enter Roll No"<<endl;
 cin>>newnode->rno;
 cout<<"Enter Name"<<endl;
 cin>>newnode->name;
 cout<<"Enter CGPA"<<endl;
 cin>>newnode->cgpa;
 newnode->next=temp->next;
 temp->next=newnode;
 flag=1;
 break;
 }
 temp=temp->next;
}
 if(flag==0)
 {
 cout<<"Node not Found"<<endl;
 }
 }
 if(ch==3)
 {
 temp=head;
 while(temp->next!=NULL)
{
 temp=temp->next;
 }
 newnode=new node;
 cout<<"\n===== Enter New Student Data ====="<<endl;
 cout<<"Enter Roll No"<<endl;
 cin>>newnode->rno;
 cout<<"Enter Name"<<endl;
 cin>>newnode->name;
 cout<<"Enter CGPA"<<endl;
 cin>>newnode->cgpa;
 newnode->next=NULL;
 temp->next=newnode;
 }
 }
 void SLL::delet()
 {
 node *temp,*prev;
 int d,flag=0,ch;
 cout<<"\n==== Enter the Choice ===="<<endl;
 cout<<"\n1.Delete First \n2.Delete Between \n3.Delete Last"<<endl;
 cin>>ch;
if(ch==1)
 {
 temp=head;
 head=head->next;
 delete(temp);
 }
 if(ch==2)
 {
 cout<<"\nEnter node to delete"<<endl;
 cin>>d;
 temp=head;
prev=NULL;
 while(temp!=NULL)
 {
 flag=1;
 cout<<"Node Found";
 prev->next=temp->next;
 delete(temp);
 break;
 }
 prev=temp;
 temp=temp->next;
 }
 if(flag==0)
 {
cout<<"\nNot Found"<<endl;
 }
 if(ch==3)
 {
 temp=head;
prev=NULL;
 while(temp->next!=NULL)
 {
 prev=temp;
 temp=temp->next;
 }
 prev->next=NULL;
 delete(temp);
 }
 }
void SLL::sort()
 {
 int newnode;
 node *temp,
*j,
*i;
 temp=head;

 for(i=temp;i!=NULL;i=i->next)
 {
 for(j=i->next;j!=NULL;j=j->next)
 {
 if(i->rno > j->rno)
 {
 newnode=i->rno;
 i->rno=j->rno;
 j->rno=newnode;
 }
 }
 }
 }
 void SLL::search()
 {
 node *temp;
 temp=head;
 int n;
 int flag=0;

 if(head==NULL)
 {
cout<<"\nList is Empty"<<endl;
 }
 else{
 cout<<"Enter the Roll No to search"<<endl;
 cin>>n;
 while(temp!=NULL){

if(temp->rno==n)
 {
 flag=1;
 cout<<temp->rno<<temp->name<<temp->cgpa<<endl;
 break;
}
temp=temp->next;
 }
 }
 }
 void SLL::display()
 {
node *temp;
 temp=head;
 cout<<"\nYour Linked List is"<<endl;
while(temp!=NULL)
{
 cout<<"RNO."<<" NAME"<<" CGPA"<<endl;
 cout<<temp->rno<<" "<<temp->name<<" "<<temp->cgpa<<endl;
 temp=temp->next;
 }
 }
 int main()
 {
 int O;
 SLL S1;
 do{
 cout<<"\n================== Select Operations to be Performed =================="<<endl;
 cout<<"\n1.Create Node\n2.Insert Node\n3.Delete Node\n4.Sort\n5.Display\n6.Search\n7.Exit"<<endl;
 cin>>O;
 switch(O)
 {
 case 1:
 cout<<"\t\t\t\t\t\ *** Enter Student Info ***"<<endl;
 S1.create();
 break;
 case 2:
 cout<<"\nInsert Info"<<endl;
 S1.insert();
 break;
 case 3:
 cout<<"\nDelete Info"<<endl;
 S1.delet();
 break;
 case 4:
S1.sort();
 break;
 case 5:
 S1.display();
 break;
 case 6:
 S1.search();
break;
 case 7:
 exit(0);
break;
default:
 cout<<"\nINVALID CHOICE"<<endl;
 break;
 }
 }while(O!=7);
 return 0;
 }

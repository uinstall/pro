#include<iostream>
using namespace std;
class node
{
 public:
 int coeff;
 int exp;
 node *next;
 node()
 {
 next=NULL;
 }
 };

 class poly
 {
 node *head;
 public:
 poly()
 {
 head=NULL;
 }
 void create();
 void sorted_insert(node *newnode);
 void display();
 void addition (poly p1,poly p2);
 void multiply (poly p1,poly p2);


 };

 void poly::create()
 {
 int ch;
 node *newnode;
 do
 {
 newnode=new node();
 cout<<"\n Enter the coefficient and exponent for the new term : ";
 cin>>newnode->coeff>>newnode->exp;
 newnode->next=newnode;
 sorted_insert(newnode);
 cout<<"Press 1 to add more..";
 cin>>ch;
 }while(ch==1);
 }

 void poly::sorted_insert(node *newnode)
 {
 if(head==NULL)
 {
 head=newnode;
 return;
 }
 node *temp,*prev;
 if(head->exp<newnode->exp)
 {
 temp=head;
 while(temp->next!=head)
 temp=temp->next;
 temp->next=newnode;
 newnode->next=head;
 head=newnode;
 return;
 }
 temp=head;
 while(1)
 {
 if(temp->exp==newnode->exp)
 {
 temp->coeff=temp->coeff+newnode->coeff;
 delete(newnode);
 break;
 }
 else if(temp->exp<newnode->exp || temp->next==head)
 {
 if(temp->exp<newnode->exp )
 {
 prev->next=newnode;
 newnode->next=temp;
 break;
 }
 else
 {
 newnode->next=temp->next;
 temp->next=newnode;
 break;
 }
 }
 else
 {
 prev=temp;
 temp=temp->next;
 }
 }

 }
 void poly::display()
 {
 node *temp;
 if(head==NULL)
 cout<<"Polynomial Empty";
 else
 {

 temp=head;
 while(temp->next!=head)
 {

 cout<<" "<<temp->coeff<<"x^"<<temp->exp<<" +";
 temp=temp->next;
}
cout<<" "<<temp->coeff<<"x^"<<temp->exp<<" =0";
}
}
void poly::addition(poly p1, poly p2)
{
if(p1.head==NULL && p2.head==NULL)
{
return;
}
node *temp,*newnode;
temp=p1.head;
do
{
newnode=new node();
newnode->coeff=temp->coeff;
newnode->exp=temp->exp;
newnode->next=newnode;
sorted_insert(newnode);
temp=temp->next;
}while(temp!=p1.head);
temp=p2.head;
do
{
newnode=new node();
newnode->coeff=temp->coeff;
newnode->exp=temp->exp;
newnode->next=newnode;
sorted_insert(newnode);
temp=temp->next;
}while(temp!=p2.head);
}
void poly::multiply(poly p1,poly p2)
{
if(p1.head==NULL && p2.head==NULL)
{
return;
}
node *q1,*q2,*newnode;
q1=p1.head;
do
{
q2=p2.head;
do
{
newnode=new node();
newnode->coeff=q1->coeff*q2->coeff;
newnode->exp=q1->exp+q2->exp;
newnode->next=newnode;
sorted_insert(newnode);
q2=q2->next;
}while(q2!=p2.head);
q1=q1->next;
}while(q1!=p1.head);
}
int main()
{
poly p1,p2,p3,p4;
p1.create();
p1.display();
p2.create();
p2.display();
p3.addition(p1,p2);
cout<<"\n\nAddition is :\n ";
p3.display();
p4.multiply(p1,p2);
cout<<"\n\n Multiplication is :\n ";
p4.display();
return 0;
}

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
 void sorted_insert(node *temp);
 void display();
 void addition (poly p1,poly p2);
 void multiply (poly p1,poly p2);


 };

 void poly::create()
 {
 int ch;
 node *new_node;
 do
 {
 new_node=new node();
 cout<<"\n Enter the coefficient and exponent for the new term : ";
 cin>>new_node->coeff>>new_node->exp;
 new_node->next=new_node;
 sorted_insert(new_node);
 cout<<"Press 1 to add more..";
 cin>>ch;
 }while(ch==1);
 }

 void poly::sorted_insert(node *new_node)
 {
 if(head==NULL)
 {
 head=new_node;
 return;
 }
 node *temp,*prev;
 if(head->exp<new_node->exp)
 {
 temp=head;
 while(temp->next!=head)
 temp=temp->next;
 temp->next=new_node;
 new_node->next=head;
 head=new_node;
 return;
 }
 temp=head;
 while(1)
 {
 if(temp->exp==new_node->exp)
 {
 temp->coeff=temp->coeff+new_node->coeff;
 delete(new_node);
 break;
 }
 else if(temp->exp<new_node->exp || temp->next==head)
 {
 if(temp->exp<new_node->exp )
 {
 prev->next=new_node;
 new_node->next=temp;
 break;
 }
 else
 {
 new_node->next=temp->next;
 temp->next=new_node;
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
node *temp,*new_node;
temp=p1.head;
do
{
new_node=new node();
new_node->coeff=temp->coeff;
new_node->exp=temp->exp;
new_node->next=new_node;
sorted_insert(new_node);
temp=temp->next;
}while(temp!=p1.head);
temp=p2.head;
do
{
new_node=new node();
new_node->coeff=temp->coeff;
new_node->exp=temp->exp;
new_node->next=new_node;
sorted_insert(new_node);
temp=temp->next;
}while(temp!=p2.head);
}
void poly::multiply(poly p1,poly p2)
{
if(p1.head==NULL && p2.head==NULL)
{
return;
}
node *q1,*q2,*new_node;
q1=p1.head;
do
{
q2=p2.head;
do
{
new_node=new node();
new_node->coeff=q1->coeff*q2->coeff;
new_node->exp=q1->exp+q2->exp;
new_node->next=new_node;
sorted_insert(new_node);
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

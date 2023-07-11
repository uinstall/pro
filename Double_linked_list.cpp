#include<iostream>
using namespace std;
class node{
public:
int data;
node *next;
node *prev;
};
class dll{
node *head;
public:
dll(){
head=NULL;
}
void create();
void display();
int length();
void search();
void insert();
void revdisplay();
void sort();
node* swap(node *p1,node *p2);
void merge(dll d1,dll d2);
};
void dll :: create(){
int ch;
node *temp,*p;
do{
temp = new node;
cout<<"Enter data"<<endl;
cin>>temp->data;
temp->prev=NULL;
temp->next=NULL;
if(head==NULL){
head=temp;
}
else{
p=head;
while(p->next!=NULL){
p=p->next;
}
p->next=temp;
temp->prev=p;

}
cout<<"------------------------------------------------------------------";
cout<<"Do you want to continue : "<<endl;
cout<<"1. Yes "<<endl;
cout<<"0. No "<<endl;
cout<<"------------------------------------------------------------------";
cin>>ch;
}
while(ch==1);
}
void dll :: display(){
node *p;
if(head==NULL){
cout<<"List is empty";
}
else{
p=head;
while(p!=NULL){
cout<<p->data<<endl;
p=p->next;
}
}
}
int dll :: length(){
int l=0;
node *p;
p=head;
while(p!=NULL){
l++;
p=p->next;
}
return l;
}
node* dll :: swap(node *p1,node *p2){
node *a,*b;
a=p1->prev;
b=p2->next;
if(p1==head){
head = head->next;
p2->next=p1;
p1->prev=p2;
p2->prev=a; //NULL
p1->next=b;
b->prev=p1;

}
else if(p2->next==NULL){
p2->next=p1;
p1->prev=p2;
p2->prev=a;
a->next=p2;
 p1->next=b; //NULL
 }
 else{
 p2->next=p1;
 p1->prev=p2;
 p2->prev=a;
 a->next=p2;
 p1->next=b;
 b->prev=p1;
 }
 return p2;
 }
 void dll :: sort(){
 node *temp,*p1,*p2;
 int i,j,l=length(),swapped=0;
 for(i=0;i<l;i++){
 swapped=0;
 temp=head;
 for(j=0;j<l-1-i;j++){
 p1=temp;
 p2=temp->next;
 if(p1->data>p2->data){
 temp=swap(p1,p2);
 swapped=1;
 }
 temp=temp->next;
 }
 if(swapped==0){
 break;
 }
 }
 cout<<"Sorted"<<endl;
 display();
 }
 void dll :: merge(dll d1,dll d2)
 {
 node *temp;
 if(d1.head==NULL)
 {
 temp=d2.head;
 }
 if(d2.head==NULL)
 {
 temp=d1.head;
 }
 temp=d1.head;
 while(temp->next!=NULL)
 {
 	temp=temp->next;
 	
 }
 
temp->next=d2.head;
temp=d1.head;
cout<<"Merging Both \n";
while(temp!=NULL)
{
	cout<<"\n"<<temp->data;
	temp=temp->next;
}
 }
 void dll :: search(){
 int d,flag=0;
 node *p;
 if(head==NULL){
 cout<<"List is empty";
 }
 else{
 cout<<"Enter data you want to search : ";
 cin>>d;
 p=head;
 while(p!=NULL){
 if(p->data==d){
 cout<<"Node found"<<endl;
 flag=1;
 break;
 }
 p=p->next;
 }
 if(flag==0){
 cout<<"Not found"<<endl;
 }
 }
 }
 void dll :: insert(){
 int ch=0,d,flag=0;
 node *temp;
 node *p;
 cout<<"Enter 1.To insert at start "<<endl;
 cout<<"Enter 2.To insert in between "<<endl;
 cout<<"Enter 3.To insert at end "<<endl;
 cin>>ch;
 if(ch==1){
 temp = new node;
 cout<<"Enter node : "<<endl;
 cin>>temp->data;
 temp->next=head;
 head = temp;
 }
 else if(ch==2)
 {
 cout<<"Enter node after which you want to insert : "<<endl;
 cin>>d;
 p=head;
 while(p!=NULL){
 if(p->data==d){
 cout<<"Node found ."<<endl;
 cout<<"Enter new node : "<<endl;
 temp=new node;
 cin>>temp->data;
 temp->next=p->next;
 p->next=temp;
 flag=1;
 break;
 }
 p=p->next;
 }
 if(flag==0){
 cout<<"Node not found"<<endl;
 }
 }
 else{
 temp=new node;
 cout<<"Enter new node : "<<endl;
 cin>>temp->data;
 temp->next=NULL;
 p=head;
 while(p->next!=NULL){
 p=p->next;
 }
 p->next=temp;
 }
 }
 void dll :: revdisplay(){
 node *p;
 node *a;
 if(head==NULL){
 cout<<"List is empty"<<endl;
 }
 else{
 p=head;
 a=head;
 while(p!=0){
 cout<<p->data<<endl;
 p=p->next;
 }
 p=p->prev;
 while(p!=NULL){
 cout<<p->data<<endl;
 p=p->prev;

 }
 }
 }
 int main()
 {
 	
 	

 dll linkedlist,l1,l2;
 int ch,c;
cout<<"Enter the Choice that you want to Perform :\n";
do{
cout<<" 1. CREATE \n 2.DISPLAY \n 3.INSERT \n 4.LENGTH \n 5.SORT \n 6.SEARCH \n 7.REVERSE DISPLAY \n 8.MERGE \n";
cin>>ch;
 switch(ch)
{
 case 1:
 l1.create();
 break;
 case 2:
 l1.display();
 break;
 case 3:
 l1.insert();
 break;
 case 4:
 l1.length();
 break;
 case 5:
 l1.sort();
 break;
 case 6:
 l1.search();
 break;
 case 7:
 l1.revdisplay();
 break;
 case 8:
 l2.create();
 l1.merge(l1,l2);
 cout<<"\n After Sorting :\n";
 l1.sort();
 break;
 default :
 	cout<<"Invalid Choice";
 	break;

}cout<<"Do you want to Continue Press 1 or 0:";
cin>>c;
}

while(c==1);

 }
 

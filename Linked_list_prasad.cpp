#include<iostream>

using namespace std;

class node{
	public:
		int rno;
		string name;
		float cgpa;
		node* next;
};

class Student_info{
	node *head;
	
	public:
		Student_info(){
			head = NULL;
		}
		node* getData();
		void create();
		void insert();
		void display();
		void del();
		void sort();
		void search();
};


node* Student_info::getData(){
	node *newNode = new node;
		
	cout<<"\t\t\t---------- Enter Student Data ----------"<<endl;
	cout<<"Enter Roll No : "<<endl;
	cin>>newNode->rno;
	
	cout<<"Enter Name : "<<endl;
	cin>>newNode->name;
	
	cout<<"Enter CGPA : "<<endl;
	cin>>newNode->cgpa;
	
	return newNode;
}

void Student_info::create(){
	int ch;
	node *newNode, *curr;
	do{
	
		newNode = getData();
				
		newNode->next = NULL;
		
		if(head == NULL){
			head = newNode;
		}else{
			curr = head;
			while(curr->next != NULL){
				curr = curr->next;
			}
			curr->next = newNode;
		}
		cout<<"Press 1 to Continue [Create] : "<<endl;
		cin>>ch;
	}while(ch == 1);
}

void Student_info::insert(){
	
	node *curr, *newNode;
	int ch, rno, flag;
	
	cout<<"1 - Start\t2 - Between\t3 - Last"<<endl;
	cout<<"Enter Your Choice : "<<endl;
	cin>>ch;
	if(ch == 1){
		
		newNode = getData();
		
		newNode->next = head;
		head = newNode;
	}
	else if(ch == 2){
		cout<<"Enter roll no after which you want to enter : ";
		cin>>rno;
		
		curr = head;
		while(curr != NULL){
			if(curr->rno == rno){
				
				newNode = getData();
				
				newNode->next = curr->next;
				curr->next = newNode;
				flag = 1;
				break;
			}
			curr = curr->next;
		}
		if(flag == 0){
			cout<<"Roll No Not Found..!"<<endl;
		}
	}
	else if(ch == 3){
		
		curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		newNode = getData();
		
		newNode->next = NULL;
		curr->next = newNode;
	}else{
		cout<<"Incorrect Choice :("<<endl;
	}
}

void Student_info::del(){
	if(head == NULL){
		cout<<"Oops ..! List is Empty :("<<endl;
	}else{
		node *curr, *prev;
	
		int ch, flag = 0, rno;
		
		cout<<"\n1 - Delete First\t2 - Delete Middle\t3 - Delete Last"<<endl;
		cout<<"````````````````````````````````````````````````````````````````````````````"<<endl;
		cout<<"Enter Choice : ";
		cin>>ch;
		if(ch == 1){
			curr = head;
			head = head->next;
			delete(curr);
		}
		else if(ch == 2){
			cout<<"Enter the roll number you want to delete : ";
			cin>>rno;
			
			curr = head;
			prev = NULL;
			while(curr != NULL){
						
				if(curr->rno == rno){
					flag = 1;
					prev->next = curr->next;
					delete(curr);
				}
				prev = curr;
				curr = curr->next;
			}
			if(flag == 0){
				cout<<"Roll no not found in the list :("<<endl;
			}
		}
		else if(ch == 3){
			curr = head;
			prev = NULL;
			while(curr->next != NULL){
				prev = curr;
				curr = curr->next;
			}
			prev->next = NULL;
			delete(curr);
		}
		else{
			cout<<"Invalid Choice :("<<endl;
		}
	}
}

void Student_info::search(){
	int ch, found = 0, rno;
	node *curr;
	
	curr = head;
	if(head == NULL){
		cout<<"Oops ..! List is Empty :("<<endl;
	}else{
		cout<<"Enter Roll No to Search : "<<endl;
		cin>>rno;
		while(curr != NULL){
			if(curr->rno == rno){
				found = 1;
				cout<<"Student Data : "<<endl;
				cout<<curr->rno<<"\t"<<curr->name<<"\t"<<curr->cgpa<<endl;
				break;
			}
			curr = curr->next;
		}
		if(found != 1){
			cout<<"Student Not Found :("<<endl;
		}
	}
}

void Student_info::sort(){
	if(head != NULL){
		int rno, ch;	
		node *curr, *i, *j, *temp;
		
		curr = head;
		for(i = curr; i != NULL; i = i->next){
			for(j = i->next; j != NULL; j = j->next){
				if(i->rno > j->rno){
					temp = i;
					i = j;
					j = temp;
				}
			}
		}
	}else{
		cout<<"Oops ..! List is Empty :("<<endl;
	}
}

void Student_info::display(){
	
	if(head == NULL){
		cout<<"Oops ..! List is Empty :("<<endl;
	}else{
		node *curr;
		curr = head;
		cout<<"Roll No\tName\tCGPA"<<endl;
		while(curr != NULL){
			cout<<curr->rno<<"\t"<<curr->name<<"\t"<<curr->cgpa<<endl;
			curr = curr->next;
		}
	}
}

int main(){
	
	Student_info si;
	int choice;
	do{
		cout<<"\n1 - Create\t2 - Insert\t3 - Display\t4 - Delete\t5 - Search\t6 - Sort\t7 - Exit"<<endl;
		cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"Enter Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				si.create();
				break;
			case 2:
				si.insert();
				break;
			case 3:
				si.display();
				break;
			case 4:
				si.del();
				break;
			case 5:
				si.search();
				break;
			case 6:
				si.sort();
				break;
			case 7:
				cout<<"\n\nThank You ! Visit Again :)"<<endl;
				exit(0);
				break;
			default:
				cout<<"Invalid Choice :("<<endl;
		}
		cout<<"Press 1 to Continue [Menu] : ";
		cin>>choice;
	}while(choice == 1);
	return 0;
}

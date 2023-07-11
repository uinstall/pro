
#include<iostream>
#include<string>

using namespace std;

class Textile
{
	public:
		string name;
		int mobile;
		string type;
		int quantity;
		string colour;
		int size;
		
	public:
		void get_info();
		void display();
		void update(Textile customer[],int size,int u);
		void insert(Textile customer[],int size,int max_size,int pos);
		void Delete(Textile customer[],int size,int e);
		
		
};

void Textile::get_info()
{
  cout<<"Enter customer name:";
  cin>>name;
  cout<<"Enter customer mobile number:";
  cin>>mobile;
  cout<<">>Enter customer order inforamtion:";
  
  cout<<"\nEnter Garment type:";
  cin>>type;
  cout<<"Enter colour:";
  cin>>colour;
  cout<<"Enter size:";
  cin>>size;
  cout<<"Enter Garment quantity:";
  cin>>quantity;
}

void Textile::display()
{
  cout<<"\nCustumer information:"<<endl;
  cout<<"customer name:"<<name<<endl;
  cout<<"customer mobile number:"<<mobile<<endl;
  cout<<">>customer order inforamtion:"<<endl;
  cout<<"Garment type:"<<type<<endl;
  cout<<"colour:"<<colour<<endl;
  cout<<"size:"<<size<<endl;
  cout<<"Garment quantity:"<<quantity<<endl;
 
}

void Textile::update(Textile customer[] , int size, int u)
{
	if(u<1 || u>size)
	{
		cout<<"You entered invalid customer number"<<endl;	
	}
	else
	{
	 cout<<"\ncustomer number:"<<	u<<endl;
	 cout<<"\ncurrent customer name:"<<customer[u-1].name<<endl;
	 cout<<"New customer name:";
	 cin>>customer[u-1].name;
	 
	 cout<<"\ncurrent customer mobile number::"<<customer[u-1].mobile<<endl;
	 cout<<"New customer mobile number: ";
	 cin>>customer[u-1].mobile;
	cout<<"\n>>Enter customer order inforamtion:"<<endl;
	 
	 cout<<"\ncurrent Garment type::"<<customer[u-1].type<<endl;
	 cout<<"New Garment type: ";
	 cin>>customer[u-1].type;
	 
	 cout<<"\ncurrent  colour::"<<customer[u-1].colour<<endl;
	 cout<<"New  colour: ";
	 cin>>customer[u-1].colour;
	 
	 cout<<"\ncurrent size:"<<customer[u-1].size<<endl;
	 cout<<"New  size: ";
	 cin>>customer[u-1].size;
	 
	 cout<<"\ncurrent Garment quantity:"<<customer[u-1].quantity<<endl;
	 cout<<"New Garment quantity: ";
	 cin>>customer[u-1].quantity;
	 
	 cout<<"\nUpdatated Data:"<<endl;
	 cout<<"\ncustomer number :"<<u;
	 customer[u-1].display();
	 
	}
	
}

void Textile::Delete(Textile customer[] , int size, int e)
{ 
 if(e<1 || e>size)
  {
	cout<<"You entered invalid customer number"<<endl;	
  }
	
 else
 {
   for(int i=e-1; i<size ;i++)	
   {
 	 customer[i].name=customer[i+1].name;
 	 customer[i].mobile=customer[i+1].mobile;
 	 customer[i].type=customer[i+1].type;
 	 customer[i].colour=customer[i+1].colour;
 	 customer[i].size=customer[i+1].size;
 	 customer[i].quantity=customer[i+1].quantity;
   }
   
     customer[size-1].name="None";
 	 customer[size-1].mobile=0;
 	 customer[size-1].type="None";
 	 customer[size-1].colour="None";
 	 customer[size-1].size=0;
 	 customer[size-1].quantity=0;
   
   cout<<"Data is deleted of customer number "<<e<<endl;	
 }
}


void Textile::insert(Textile customer[],int size,int max_size, int pos)
{
	if(pos>size || pos<=0 || size>=max_size) 
	{
		cout<<"insert operation does not possible....."<<endl;
	}
	else
	{
		for(int i=pos;i<=size;i++)
		{
		   customer[i].name=customer[i-1].name;
 	       customer[i].mobile=customer[i-1].mobile;
 	       customer[i].type=customer[i-1].type;
 	       customer[i].colour=customer[i-1].colour;
 	       customer[i].size=customer[i-1].size;
 	       customer[i].quantity=customer[i-1].quantity;	
		}	
		
		cout<<"Enter the data to insert at customer number "<<pos<<endl;
        cout<<"\ncustomer number :"<<pos<<endl;
        customer[pos-1].get_info();	
        
		cout<<"Data inserted successfuly...."<<endl;
	}
	
}


int main()
{ 
 int m,n,choice;
 cout<<"\nEnter maximum number of customer to store their Data:";
 cin>>m;
 Textile customer[m];
 cout<<"\nEnter number of customer to store their data now:";
  cin>>n;
  
  for (int i=0;i<n;i++)
  { cout<<"\ncustomer number :"<<i+1<<endl;
    customer[i].get_info();	
  }
  
  do
 {
   cout<<"\nList of operations:" ;
   cout<<"\n 1.Press 1 to display\n 2..Press 2 to update\n 3..Press 3 to Delete\n 4..Press 4 to Insert\n 5..Press 0 to Exit"<<endl;
   cout<<"Enter your choice;"<<endl;
   cin>>choice;

   switch(choice)	
   {
   	case 1:
   	  cout<<"\nDISPLAY OPERATION:";
   	  for (int i=0;i<n;i++)
   	  {
       cout<<"\ncustomer number:"<<i+1;
       customer[i].display();	
      }
	break;
	
	case 2:
	int u;
	cout<<"\nUPDATE OPERATION:";
	cout<<"\nEnter customer number to update Data :";
	cin>>u;	
	customer[u-1].update(customer,n,u);
	
	break;
	
	case 3:
	int e;
	cout<<"\nDELETE OPERATION:";
	cout<<"\nEnter customer number to Delete Data:";	
	cin>>e;
	customer[e-1].Delete(customer,n,e);
	n=n-1;
	break;
	
	case 4:
	int pos;
	cout<<"\nINSERT OPERATION:";
	cout<<"\nEnter customer number at which you want to Insert Data:";	
	cin>>pos;
	customer[pos-1].insert(customer,n,m,pos);
	n=n+1;
	break;
	
	case 0:
	cout<<"\nYour work is completed..."<<endl;
	break;
	
	default:
	cout<<"\nYou entered invalid choice....."<<endl;
	break;
   }
 
 }while(choice!=0);
	
	
	return 0;
	
}



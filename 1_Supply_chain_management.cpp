#include<iostream>
#include<string>

using namespace std;

class Textile_Flipkart
{
	public:
		string name;
		long mobile;
		string product_name;
		int quantity;
		int ram;
		int storage;
		
	public:
		void get_info();
		void display();
		void update(Textile_Flipkart customer[],int storage,int u);
		void insert(Textile_Flipkart customer[],int storage,int max_storage,int pos);
		void Delete(Textile_Flipkart customer[],int storage,int e);
		
		
};

void Textile_Flipkart::get_info()
{
  cout<<"Enter Customer Name:";
  cin>>name;
  cout<<"Enter Customer Mobile Number:"<<"\n";
  cin>>mobile;
  cout<<">>Enter Customer Order Information:";
  
  cout<<"\nEnter Product Name (Mobile Model):";
  cin>>product_name;
  cout<<"Enter Ram (in GB) :";
  cin>>ram;
  cout<<"Enter Storage(in GB):";
  cin>>storage;
  cout<<"Enter Quantity:";
  cin>>quantity;
}

void Textile_Flipkart::display()
{
  cout<<"\n*** Customer Information ***"<<endl;
  cout<<"Customer Name:"<<name<<endl;
  cout<<"Customer mobile number:"<<mobile<<endl;
  cout<<">>Customer order information:"<<endl;
  cout<<"Product Name:"<<product_name<<endl;
  cout<<"Ram:"<<ram<<endl;
  cout<<"Storage:"<<storage<<endl;
  cout<<"Quantity:"<<quantity<<endl;
 
}

void Textile_Flipkart::update(Textile_Flipkart customer[] , int storage, int u)
{
	if(u<1 || u>storage)
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
	 
	 cout<<"\nCurrent Product Name::"<<customer[u-1].product_name<<endl;
	 cout<<"New Product Name: ";
	 cin>>customer[u-1].product_name;
	 
	 cout<<"\nCurrent  Ram::"<<customer[u-1].ram<<endl;
	 cout<<"New Ram: ";
	 cin>>customer[u-1].ram;
	 
	 cout<<"\nCurrent Storage:"<<customer[u-1].storage<<endl;
	 cout<<"New Storage: ";
	 cin>>customer[u-1].storage;
	 
	 cout<<"\nCurrent Quantity:"<<customer[u-1].quantity<<endl;
	 cout<<"New Quantity: ";
	 cin>>customer[u-1].quantity;
	 
	 cout<<"\nUpdatated Data:"<<endl;
	 cout<<"\nCustomer Number :"<<u<<"\n";
	 customer[u-1].display();
	 
	}
	
}

void Textile_Flipkart::Delete(Textile_Flipkart customer[] , int storage, int e)
{ 
 if(e<1 || e>storage)
  {
	cout<<"You entered invalid customer number !!"<<endl;	
  }
	
 else
 {
   for(int i=e-1; i<storage ;i++)	
   {
 	 customer[i].name=customer[i+1].name;
 	 customer[i].mobile=customer[i+1].mobile;
 	 customer[i].product_name=customer[i+1].product_name;
 	 customer[i].ram=customer[i+1].ram;
 	 customer[i].storage=customer[i+1].storage;
 	 customer[i].quantity=customer[i+1].quantity;
   }
   
     customer[storage-1].name="None";
 	 customer[storage-1].mobile=0;
 	 customer[storage-1].product_name="None";
 	 customer[storage-1].ram=0;
 	 customer[storage-1].storage=0;
 	 customer[storage-1].quantity=0;
   
   cout<<"Data is deleted of customer number :"<<e<<endl;	
 }
}


void Textile_Flipkart::insert(Textile_Flipkart customer[],int storage,int max_storage, int pos)
{
	if(pos>storage || pos<=0 || storage>=max_storage) 
	{
		cout<<"insert operation does not possible....."<<endl;
	}
	else
	{
		for(int i=pos;i<=storage;i++)
		{
		   customer[i].name=customer[i-1].name;
 	       customer[i].mobile=customer[i-1].mobile;
 	       customer[i].product_name=customer[i-1].product_name;
 	       customer[i].ram=customer[i-1].ram;
 	       customer[i].storage=customer[i-1].storage;
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
 Textile_Flipkart customer[m];
 cout<<"\nEnter number of customer to store their data now:";
  cin>>n;
  
  for (int i=0;i<n;i++)
  { cout<<"\nCustomer Number :"<<i+1<<endl;
    customer[i].get_info();	
  }
  
  do
 {
   cout<<"\nList of operations:" ;
   cout<<"\n 1.Press 1 to display\n 2.Press 2 to update\n 3.Press 3 to Delete\n 4.Press 4 to Insert\n 5.Press 0 to Exit"<<"\n"<<endl;
   cout<<"Enter your choice:"<<endl;
   cin>>choice;

   switch(choice)	
   {
   	case 1:
   	  cout<<"\nDISPLAY OPERATION:";
   	  for (int i=0;i<n;i++)
   	  {
       cout<<"\nCustomer Number:"<<i+1;
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


#inlcude<iostream.h>
using namespace std;

int main()
{int n,s;
cout<<"How many elemets you want"
cin>>n;
    int arR[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the elements";
        cin>>arr[i];

    }
int temp;

 for(int i=0;i<n;i++)
 {
    for(int j=0;j<n;j++)
    {
        if(arr[i]>arr[j])
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[i]=temp;
        }
    }
 }  
 for(int i=0;i<n;i++)
 {
    cout<<arr[i];

 }
return 0;
}
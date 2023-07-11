#include<iostream>
 #include<string.h>
 #include<string>
 #include<bits/stdc++.h>
 
 #define size 100

 using namespace std;
 
 class Stack
 {
 public :
 
 string stack[size];
 int top;
 
 Stack()
 {
 top=-1;
 }
 
 bool isFull()
 {
 if(top==size-1)
 return true;
 else
 return false;
 }
 
 bool isEmpty()
 {
 if(top==-1)
 return true;
 else
 return false;
 }
 
 void push(string s)
 {
 if(isFull())
 cout<<"\nStack is full\n";
 else
 top++;
 stack[top]=s;
 }
 
 string pop()
 {
 string temp;
if(isEmpty())
cout<<"\nStack is empty\n";
 else
 temp= stack[top];
 top--;
return temp;
 }
 };
 
 class Expression
 {
public:
 string postfix,prefix;
 string infix;
 Stack s;
 
 bool isoperator(char x)
 {
 if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' )
 return true;
 else
 return false;
 }

 int precedance(string op)
 {
if(op=="+" || op=="-")
 return 1;
 else if(op=="*" || op=="/")
 return 2;
else if(op=="^")
return 3;
 else
 return 0;
}
 
 void infix_to_postfix()
 {
 cout<<"Enter infix expression:\n";
cin>>infix;
 
 for(int i=0;i<infix.length();i++)
 {
 if((infix[i]>='a' && infix[i]<= 'z') || (infix[i]>='A' && infix[i]<='Z'))
 {
postfix=postfix+infix[i];
 }
 
else if(infix[i]=='(')
 {
 s.push("(");
 }
 
 else if(infix[i]==')')
 {
 while((!s.isEmpty()) && (s.stack[s.top]!="("))
 {
 string t=s.stack[s.top];
 s.pop();
 
 }
 
 if(s.stack[s.top]=="(")
 {
 s.pop();
 }

 }
 
 else
 {
while((!s.isEmpty()) && precedance(string(1,infix[i]))<= precedance(s.stack[s.top]))
{
string t=s.stack[s.top];
s.pop();
 postfix=postfix+t;
 }
 s.push(string(1,infix[i]));
 }
 }
 
 while(!(s.isEmpty()))
 {
 string t=s.stack[s.top];
 s.pop();
 postfix=postfix+t;
 }
 
 cout<<"\n\n**INFIX EXPRESSION**\n";
 cout<<infix;
 cout<<"\n\n**POSTFIX EXPRESSION**\n";
 cout<<postfix;
 cout<<"\n\n";
 }
 
 void postfix_to_prefix()
 {
 cout<<"Enter Postfix expression:\n";
 cin>>postfix;
 
 for(int i=0;i<postfix.length();i++)
 {
 
 if(isoperator(postfix[i]))
 {
string op2=s.pop();
 string op1=s.pop();
 string temp=postfix[i]+op1+op2;
 s.push(temp);
 }
 else
 {
 s.push(string(1,postfix[i]));
}
 }
 
 prefix=s.pop();
 cout<<"\n\n**POSTFIX EXPRESSION**\n";
 cout<<postfix;
 cout<<"\n\n**PREFIX EXPRESSION**\n";
 cout<<prefix;
 cout<<"\n\n";
 
 }
 
 void postfix_evaluation()
 {
 cout<<"Enter postfix expression to be evaluate:\n";
 cin>>postfix;
 
 cout<<"\n\n**POSTFIX EXPRESSION TO BE EVALUATE**\n";
 cout<<postfix;
 
 for(int i=0;i<postfix.length();i++)
 {
 if(isoperator(postfix[i]))
 {
 
 int op_1,op_2;
 int ans;
 string op2=s.pop();
 string op1=s.pop();
 
stringstream stm1(op1);
 stringstream stm2(op2);
 
 stm1>>op_1;
 stm2>>op_2;

 if(postfix[i]=='+')
 {
 ans=op_1+op_2;
 }
 else if(postfix[i]=='-')
 {
 ans=op_1-op_2;
 }
 else if(postfix[i]=='*')
 {
 ans=op_1*op_2;
 }
 else if(postfix[i]=='/')
 {
 ans=op_1/op_2;
}
 else if(postfix[i]=='^')
{
ans=pow(op_1,op_2);
 }
 
 // else{}
 
 stringstream stm3;
stm3<< ans;
 string ans1=stm3.str();
 s.push(ans1);
 }
 
 else
 {
if(isdigit(postfix[i]))
 {
 s.push(string(1,postfix[i]));
 }
 }
 }
 
 
cout<<"\n*****RESULT*******\n";
 string result=s.pop();
 cout<<"\nRESULT : "<<result;
 cout<<"\n\n";
 
 }
 };

int main()
 {
 Expression e ;
 int ch,c;
 
 do
 {
cout<<"Enter your choice:\n";
 cout<<"\n1.Infix to Postfix Conversion\n";
 cout<<"2.Postfix to Prefix Conversion\n";
 cout<<"3.Postfix Evaluation\n";
 cin>>ch;
 
 switch(ch)
 {
 case 1:
 e.infix_to_postfix();
 break;

 case 2:
 e.postfix_to_prefix();
 break;
 
case 3:
 e.postfix_evaluation();
 break;
 
 default:
 cout<<"\nEnter valid choice:\n";
 
 }
 
 cout<<"\nPress 0 to exit\n";
 cin>>c;
 
 
 } while(c!=0);
 return 0;
 }

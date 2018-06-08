#include <iostream>
using namespace std;
#include<string.h>
#include<math.h>
void push( int aStack[], int *top, int aRemainder );
char pop( int aStack[], int *top );
char num[25];
int any_base_to_decimal(char num[],int ibase)
{
    int i,p=0;
    int a=strlen(num);
    for(i=a-1;i>=0;i--)

    {
        if (((int) num[i]-48)<ibase && (int) num[i]>=48 && (int) num[i]<=57)
            p+=((int) num[i]-48)*pow(ibase,a-i-1);
        else if (((int) num[i]-55)<ibase && (int)num[i]>=65 && (int) num[i]<=90)
            p+=((int) num[i]-55)*pow(ibase,a-i-1);
        else if (((int) num[i]-61)<ibase && (int)num[i]>=97 && (int) num[i]<=122)
            p+=((int) num[i]-61)*pow(ibase,a-i-1);
        else
            return -1;
    }
    return p;
}
void decimal_to_any_base(int innum,int outbase)
{
    // stack created
    int stack1[100];
    int * top;
    top = new int;
    *top=-1;
	int remainder;
    // loop to get the remainders based on the base
	while ( innum != 0)
	{
		remainder = innum%outbase;

        push(stack1, top, remainder);
        innum /= outbase;
	}
	cout<<"THE CONVERTED NUMBER IS :";
	while (*top>=0) {
		cout << pop(stack1, top);
	}
}

void push(int stack1[], int *top, int aRemainder)
{
 if(*top < 100 )
 {
 *top = *top + 1;
 stack1[*top] = aRemainder;
  }
}

char pop(int stack1[], int *top)
{
 if(*top>=0 )
 { int value;
  char op[120]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
 value = stack1[*top];
 *top = *top - 1;
 return op[value];
 }
}
int main()
{
    cout<<"    \tDSA PROJECT     "<<endl;
    cout<<"submitted by:- SHIVANG RAJ (15BCE0691) \n"<<endl;
    cout<<"Let's convert bases of the numbers \n\n\n"<<endl;
    int innum,outbase,inter;
    char a,ch;
    int ibase;
    do{
    cout<<"THE NUMBER TO BE CONVERTED: ";
    cin>>num;
    cout<<"THE BASE OF THE INPUT NUMBER : ";
    cin>>ibase;
    cout<<"THE BASE OF THE OUTPUT NUMBER  :";
    cin>>outbase;
    inter=any_base_to_decimal(num,ibase);
    cout<<"intermediate decimal (base 10 number) : ";
    if (inter>=0)
        cout<<inter<<endl;
    else
        cout<<"invalid input"<<endl;

    decimal_to_any_base(inter,outbase);
    cout<<"\nDo you wish to continue?(y/n)\n";
    cin>>ch;
    } while (ch=='Y' || ch=='y');
} 

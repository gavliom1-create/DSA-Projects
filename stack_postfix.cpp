#include<iostream>
#include<cmath>
using namespace std;

class Stack 
{
    private:
    int arr[100];
    int top;

    public:
    Stack()
    {
        top=-1;
    }
    void push(int val)
    {
        arr[++top]=val;
    }
    int pop()
    {
        int p=arr[top--];
        return p;
    }

};

int evaluate(char x,int op1, int op2)
{
    if(x=='+') return(op1+op2);
    if(x=='-') return(op1-op2);
    if(x=='*') return(op1*op2);
    if(x=='/') return(op1/op2);
    if(x=='%') return(op1%op2);
    if(x=='$') return(pow(op1,op2));
}

int main(void)
{
    Stack s;
    char x;
    int op1,op2,val;

    cout<<"\n Enter postfix Expression :";
    while((x=getchar()) !='\n')
    {
        if(isdigit(x))
        {
            s.push(x-48);
        }
        else
        {
            op2=s.pop();
            op1=s.pop();

            val=evaluate(x,op1,op2);
            s.push(val);
        }
    }
    val=s.pop();
    cout<<"\n Answer="<<val;
    return 0;
}

/*PS C:\Users\91782\OneDrive\Documents\GitHub\CC2 Stack and Queues> cd "c:\Users\91782\OneDrive\Documents\GitHub\CC2 Stack and Queues\" ; if ($?) { g++ stack_postfix.cpp -o stack_postfix } ; if ($?) { .\stack_postfix }

 Enter postfix Expression :623+-382/+*2$3+

 Answer=52*/
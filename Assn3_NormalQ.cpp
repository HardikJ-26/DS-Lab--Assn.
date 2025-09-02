//Q1 Implementing Stack using Arrays
/*
#include<bits/stdc++.h>
using namespace std;

class Stack
{
    int size;
    int *a;
    int top;
    public:
    Stack(int s=1000)
    {
        top=-1;
        size=s;
        a=new int[size];
    }
    ~Stack()
    {
        delete[] a; //freeing accumalated stack size
    }
    void push(int x)
    {
        if(top==size-1)
        {
            cout<<"Stack Overflow!,Cannot push "<<x<<endl;
            return;
        }
        a[++top]=x;
        cout<<x<<" is pushed"<<endl;
    }
    int pop()
    {
        if(top==-1)
        {
            cout << "Stack Underflow!,Cannot pop"<< endl;
            return -1;
        }
        cout<<"Pop Successful";
        return a[top--];
    }
    bool isEmpty()
    {
        if(top==-1)
        return true;
        else
        return false;
    }
    bool isFull()
    {
        if(top==size-1)
        return true;
        else
        return false;
    }
    void display()
    {
        if(top==-1)
        {
        cout<<"Stack is empty";
        return;
        }
        for(int i=top;i>=0;i--)
        {
            cout<<a[i]<<" ";
        }
    }
    int peek()
    {
        if(top==-1)
        {
        cout<<"Stack is empty";
        return -1;
        }
        else
        return a[top];
    }
};
int main()
{   
    Stack s(5);
    int c;
    //passing initial values of stack for testing
    s.push(6);
    s.push(3);
    s.push(7);

    cout<<"Make your choice from following menu:-"<<endl;
    cout<<"1.push() \n 2.pop() \n 3.isEmpty() \n 4.isFull() \n 5.display() \n 6.peek()"<<endl;
    cin>>c;

    switch(c)
    {
        case 1:
        {
            cout<<"Enter the element to be pushed";
            int ele;
            cin>>ele;
            s.push(ele);
            break;
        }
        case 2:
        {
            s.pop();
            break;
        }
        case 3:
        {
            bool ans=s.isEmpty();
            if(ans==true)
            cout<<"Stack is empty";
            else
            cout<<"Stack is not empty";
            break;
        }
        case 4:
        {
            bool ans=s.isFull();
            if(ans==true)
            cout<<"Stack is full";
            else
            cout<<"Stack is not full";
            break;
        }
        case 5:
        {
            s.display();
            break;
        }
        case 6:
        {
            cout<<"Peek value is "<<s.peek()<<endl;
            break;
        }
    }

    // Testing underflow
    s.pop();
    s.pop();
    s.pop();
    return 0;
}
//TC-O(n),SC-O(n)
*/

//Q2 Reversing String
/*
#include <bits/stdc++.h>
using namespace std;

string reversestring(string s)
{
    int l=s.length();
    stack<char>st;
    for(int i=0;i<l;i++)
    {
        st.push(s[i]);
    }
    string result="";
    for(int i=0;i<l;i++)
    {
        result+=st.top();
        st.pop();
    }
    return result;
}
int main()
{
    string s="DataStructure";
    cout<<"Reversed String is "<<reversestring(s);
    return 0;
}
    */

//Q3 Balanced Parenthesis
/*
#include <bits/stdc++.h>
using namespace std;

bool isvalid(string s)
{
stack<int>st;
for(auto it:s)
{
    if(it=='{' || it=='(' ||  it=='[')
    st.push(it);
    else
    {
        if(st.size()==0)
        return false;
        char ch=st.top();
        st.pop();
        if(ch=='(' && it==')' || it=='}' && ch=='{' || it==']' && ch=='[')
        continue;
        else
        return false;
    }
}
return st.empty();
}
int main()
{
    string s="()[{}()]";
    if(isvalid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q4 Infix to Postfix
/*
#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if(c=='^')
    return 3;
    else if(c=='/' || c=='*')
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else
    return -1;
}
void infixtopostfix(string s)
{
    stack<char>st;
    string result;
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z' || c>='0' && c<='9'))
        result+=c;
        else if(c=='(')
        st.push(c);
        else if(c==')')
        {
            while(st.top()!='(')
            {
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && prec(c)<=prec(st.top()))
            {
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    cout<<"Postfix Expression is "<<result<<endl;
}
int main()
{
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " <<exp <<endl;
    infixtopostfix(exp);
    return 0;
}
//TC/SC-O(N)
*/

//Q5 Evaulation of Postfix Expression
/*
#include <bits/stdc++.h>
using namespace std;

int evalpost(string exp)
{
    int l=exp.length();
    stack<int>st;
    for(int i=0;i<l;i++)
    {
        char c=exp[i];
        if(isdigit(c))
        st.push(c-'0');
        else
        {
            int val2=st.top();
            st.pop();
            int val1=st.top();
            st.pop();
            switch(c)
            {
                case '+':st.push(val1+val2);
                break;
                case '-':st.push(val1-val2);
                break;
                case '*':st.push(val1*val2);
                break;
                case '/':st.push(val1/val2);
                break;
                case '^':st.push(val1^val2);
                break;

            }
        }
    }
    return st.top();
}
int main()
{
    string exp="57+62-*";
    cout<<"Value of postfix expression is "<<evalpost(exp)<<endl;
    return 0;
}
    */


//Q1 Menu Driven Program for Simple Queues
/*
#include <bits/stdc++.h>
using namespace std;

class Queue
{
int maxnum=10;
int front,rear;
int queue[10];
public:
Queue()
{
front=rear=-1;
}
bool isFull()
{
    if(rear==maxnum-1)
    return true;
    else
    return false;
}
void enqueue(int item)
{
if(isFull())
{
    cout<<"Queue Overflow"<<endl;
}
else if(front==-1 || rear==-1)
{
front=rear=0;
queue[rear]=item;
cout<<"Element enqueued is "<<item<<endl;
}
else
{
    rear++;
    queue[rear]=item;
    cout<<"Element enqueued is "<<item<<endl;
}
}
bool isEmpty()
{
    if(front==-1 || front>rear)
    return true;
    else
    return false;
}
void size()
{
   int s=rear-front+1;
   cout<<"Size of the queue presently is "<<s<<endl;
}
void dequeue()
{
    int item;
    if(isEmpty())
    {
        cout<<"Queue Underflow"<<endl;
    }
    else if(front==rear)
    {
    item=queue[front];
    cout<<"Element dequeued is "<<item<<endl;
    front=rear=-1;
    }
    else
    {
        item=queue[front];
        cout<<"Element dequeued is "<<item<<endl;
        front++;
    }
}
void peek()
{   
    if(isEmpty())
    cout<<"Queue Empty"<<endl;
    else
    cout<<"Topmost element in the queue is "<<queue[front]<<endl;
}
void display()
{
    if(isEmpty())
    cout<<"Queue is Empty"<<endl;
    else
    {
        for(int i=front;i<=rear;i++)
        cout<<queue[i]<<" ";
        cout<<endl;
    }
}
};
int main()
{
    Queue q;
    q.display();
    q.enqueue(10);    
    q.enqueue(20);
    q.display();
    q.dequeue();
    q.enqueue(30);
    q.size();
    q.enqueue(40);
    q.dequeue();
    q.peek();
    q.enqueue(50);
    q.enqueue(60);   
    q.display();
    return 0;
}
TC/SC-O(1)
    */

//Q2 Menu Driven Program for Circular Queues
/*
#include <bits/stdc++.h>
using namespace std;

class Queue
{
int maxnum=10;
int front,rear;
int queue[10];
public:
Queue()
{
front=rear=-1;
}
bool isFull()
{
    if(front==0 && rear==maxnum-1)
    return true;
    else if(front==rear+1)
    return true;
    else
    return false;
}
void enqueue(int item)
{
if(isFull())
{
    cout<<"Queue Overflow"<<endl;
}
else if(front==-1)
{
front=0;
rear=(rear+1)%maxnum;
queue[rear]=item;
cout<<"Element enqueued is "<<item<<endl;
}
else
{
    rear=(rear+1)%maxnum;
    queue[rear]=item;
    cout<<"Element enqueued is "<<item<<endl;
}
}
bool isEmpty()
{
    if(front==-1)
    return true;
    else
    return false;
}
void dequeue()
{
    int item;
    if(isEmpty())
    {
        cout<<"Queue Underflow"<<endl;
    }
    else if(front==rear)
    {
    item=queue[front];
    cout<<"Element dequeued is "<<item<<endl;
    front=rear=-1;
    }
    else
    {
        item=queue[front];
        cout<<"Element dequeued is "<<item<<endl;
        front=(front+1)%maxnum;
    }
}
void peek()
{   
    if(isEmpty())
    cout<<"Queue Empty"<<endl;
    else
    cout<<"Topmost element in the queue is "<<queue[front]<<endl;
}
void display()
{
    if(isEmpty())
    cout<<"Queue is Empty"<<endl;
    else
    {
        int i = front;
        while (true) 
        {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % maxnum;
        }
    }
}
};
int main()
{
    Queue q;
    q.display();
    q.enqueue(10);    
    q.enqueue(20);
    q.display();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.peek();
    q.enqueue(50);
    q.enqueue(60);   
    q.display();
    return 0;
}
TC/SC-O(1)
    */

//Q3 Interleaving the Queue
/*
#include <bits/stdc++.h>
using namespace std;

void interleave(queue<int>&q)
{
    int n=q.size();
    queue<int>firsthalf,secondhalf;
    for(int i=0;i<n/2;i++)
    {
        firsthalf.push(q.front());
        q.pop();
    }
    while(!q.empty())
    {
        secondhalf.push(q.front());
        q.pop();
    }
    while(!firsthalf.empty() && !secondhalf.empty())
    {
        q.push(firsthalf.front());
        firsthalf.pop();
        q.push(secondhalf.front());
        secondhalf.pop();
    }
}
int main()
{
    queue<int>q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);
    interleave(q);
    cout<<"Interleaved queue is "<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
TC/SC-O(N)
    */

//Q4 FIRST NON REPETITION
/*
#include <bits/stdc++.h>
using namespace std;

void firstnonrepeating(string s)
{
    queue<int>q;
    unordered_map<char,int>hashmap;
    for(int i=0;i<s.length();i++)
    {
        q.push(s[i]);
        hashmap[s[i]]++;
        while(!q.empty())
        {
            if(hashmap[q.front()]>1)
            q.pop();
            else
            {
                cout<<(char)q.front()<<" ";
                break;
            }
        }
        if(q.empty())
        cout<<-1<<" ";
    }
    cout<<endl;
}
int main()
{
    string str="aabc";
    firstnonrepeating(str);
    return 0;
}
TC/SC-O(N)
    */

//Q5a Implementing stack using 1 queues
/*
#include <bits/stdc++.h>
using namespace std;

class Stack
{
queue<int>q;
public:
void Push(int x)
{
    int s=q.size();
    q.push(x);
    for(int i=0;i<s;i++)
    {
        q.push(q.front()); //front() is used for getting first index in queue
        q.pop();
    }
}
int Pop()
{
    int n=q.front();
    q.pop();
    return n;
}
int Top()
{
    return q.front();
}
int Size()
{
    return q.size();
}
bool empty()
{
    return Size()==0;
}
};
int main()
{
Stack s;
s.Push(3);
s.Push(2);
s.Push(4);
s.Push(1);
cout << "Top of the stack: " << s.Top() << endl;
cout << "Size of the stack before removing element: " << s.Size() << endl;
cout << "The deleted element is: " << s.Pop() << endl;
cout << "Top of the stack after removing element: " << s.Top() << endl;
cout << "Size of the stack after removing element: " << s.Size();
return 0;
}
TC/SC-O(N)
*/

//Q5b Implementing stack using 2 queues
/*
#include<bits/stdc++.h>
using namespace std;

class convertqtos 
{
    queue<int> q1, q2;
public:
    void push(int x) 
    {
        q2.push(x);

        while (!q1.empty()) 
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }
    int size() 
    { 
    return q1.size(); 
    }
};

int main() {
    convertqtos st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    return 0;
}
TC/SC-O(N)
    */


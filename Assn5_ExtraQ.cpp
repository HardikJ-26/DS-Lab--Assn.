//Q1 Y-INTERSECTION POINT
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
{
    data=data1;
    next=next1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
}
};
void printll(Node* head)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getdifference(Node* head1,Node* head2)
{
   int len1=0,len2=0;
   while(head1!=nullptr || head2!=nullptr)
   {
    if(head1!=nullptr)
    {
        ++len1;
        head1=head1->next;
    }
    if(head2!=nullptr)
    {
        ++len2;
        head2=head2->next;
    }
   }
   return len1-len2; 
}
Node* findintersection(Node* head1,Node* head2)
{
    int diff=getdifference(head1,head2);
    if(diff<0)
    while(diff++!=0)
    head2=head2->next;
    else
    while(diff--!=0)
    head1=head1->next;
    while(head1!=nullptr)
    {
        if(head1==head2)
        return head1;
        head1=head1->next;
        head2=head2->next;
    }
    return NULL;
}
int main()
{
    Node* head1=new Node(1);
    head1->next=new Node(3);
    head1->next->next=new Node(1);
    head1->next->next->next=new Node(2);
    head1->next->next->next->next=new Node(4);
    Node* head2=new Node(3);
    head2->next=head1->next->next->next;
    head2->next->next=head1->next->next->next->next;
    cout<<"Original Linkedlist1 is "<<endl;
    printll(head1);
    cout<<"Original Linkedlist2 is "<<endl;
    printll(head2);
    Node* answerNode = findintersection(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->data<<endl;
    return 0;
}
//TC-O(N),SC-O(1)
    */

//Q2 REVERSE K NODES
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
{
    data=data1;
    next=next1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
}
};
Node* reversekgroup(Node* head, int k)
{
    Node* current = head;
    Node* temp = head;
    int cnt = 0;
    while (temp && cnt < k) 
    {
        temp = temp->next;
        cnt++;
    }
    if (cnt < k) {
        return head;
    }
    Node* prev = NULL;
    Node* nextNode = NULL;
    int nodeCount = 0;
    while (nodeCount < k) 
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
        nodeCount++;
    }
    head->next = reversekgroup(nextNode, k);
    return prev;
}
void printll(Node* head)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* head=new Node(1);
    head->next=new Node(0);
    head->next->next=new Node(2);
    head->next->next->next=new Node(0);
    head->next->next->next->next=new Node(2);
    head->next->next->next->next->next=new Node(1);
    cout<<"Original Linkedlist is "<<endl;
    printll(head);
    cout<<"Enter value of k "<<endl;
    int k;
    cin>>k;
    Node* newhead=reversekgroup(head,k);
    cout<<"New Linkedlist is "<<endl;
    printll(newhead);
    return 0;
}
//TC-O(N),SC-O(1)
    */

//Q3 REMOVING A LOOP
/*
#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    Node(int data1, Node* next1) 
    {
    data=data1; 
    next=next1; 
    }
    Node(int data1)
    {
    data=data1;
    next=nullptr;
    }
};

void printll(Node* head) 
{
    Node* temp=head;
    int cnt=0;
    while (temp != nullptr && cnt<50) 
    {
        cout<<temp->data<< " ";
        temp=temp->next;
        cnt++;
    }
    cout<<endl;
}

Node* removeloop(Node* head) 
{
    if (!head || !head->next)
    return head;

    Node *slow = head, *fast = head;
    bool loopFound = false;

    while (fast && fast->next) 
    {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) 
        {
            loopFound = true;
            break;
        }
    }
    if (!loopFound) 
    return head;

    slow=head;
    while (slow->next != fast->next) 
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = nullptr;
    return head;
}

int main() 
{
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next = head->next->next;

    head = removeloop(head);
    cout << "Linked list after loop removal:\n";
    printll(head);

    return 0;
}
//TC-O(N),SC-O(1)
*/

//Q4 ROTATE A LL
/*
#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    Node(int data1, Node* next1) 
    {
    data=data1; 
    next=next1; 
    }
    Node(int data1)
    {
    data=data1;
    next=nullptr;
    }
};

Node* rotateright(Node* head,int k) 
{
    if(head == NULL||head->next==NULL||k == 0) 
    return head;
    Node* temp=head;
    int length=1;
    while(temp->next!=NULL) 
    {
        ++length;
        temp=temp->next;
    }
    temp->next=head;
    k=k%length;
    int end=length-k;
    while(end--) 
    temp=temp->next;
    head=temp->next; //changing to new head
    temp->next = NULL; //breaking the link
        
    return head;
}

void printll(Node* head) 
{
    Node* temp=head;
    int cnt=0;
    while (temp != nullptr && cnt<50) 
    {
        cout<<temp->data<< " ";
        temp=temp->next;
        cnt++;
    }
    cout<<endl;
}
int main() 
{
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(8);
    head->next->next->next->next->next = new Node(6);

    cout<<"Original Linkedlist is "<<endl;
    printll(head);
    cout<<"Enter value of k "<<endl;
    int k;
    cin>>k;
    Node* newhead=rotateright(head,k);
    cout<<"New Linkedlist is "<<endl;
    printll(newhead);
    return 0;
}
//TC-O(N),SC-O(1)
*/

//Q5 ADD TWO NUMBERS
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
{
    data=data1;
    next=next1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
}
};
void printll(Node* head)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* reversell(Node* head)
{
    Node* prev=NULL;
    Node* temp=head;
    while(temp)
    {
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* addtwonum(Node* l1,Node* l2)
{
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry)
    {
        int sum=0;
        if(l1!=NULL)
        {
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL)
        {
            sum+=l2->data;
            l2=l2->next;
        }
        sum=sum+carry;
        carry=sum/10;
        Node* node=new Node(sum%10);
        temp->next=node;
        temp=temp->next;
    }
    return dummy->next;
}
int main()
{
    Node* head1=new Node(9);
    head1->next=new Node(9);
    head1->next->next=new Node(9);
    Node* head2=new Node(1);
    head2->next=new Node(0);
    head2->next->next=new Node(2);
    cout<<"Original Linkedlist1 is "<<endl;
    printll(head1);
    cout<<"Original Linkedlist2 is "<<endl;
    printll(head2);
    Node* reversedhead1=reversell(head1);
    Node* reversedhead2=reversell(head2);
    Node* newhead=addtwonum(reversedhead1,reversedhead2);
    newhead=reversell(newhead);
    cout<<"New Linkedlist is "<<endl;
    printll(newhead);
    return 0;
}
TC/SC-O(MAX(M,N))
    */
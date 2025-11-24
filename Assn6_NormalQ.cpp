//Q1 INSERTION-DELETION-SEARCH
//FOR DOUBLY LINKED LIST
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convert2dll(vector<int> &a)
{
    Node *head = new Node(a[0]);
    Node *prev = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i], nullptr, prev);
        prev->next = temp; // this is doing forward linking
        prev = temp;
    }
    return head;
}
void printll(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *deletehead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *prev = head;
    head = head->next;
    prev->next = nullptr;
    head->back = nullptr;
    delete prev;
    return head;
}
Node *deletetail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *tail = head;
    Node *prev;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}
Node *deletekele(Node *head, int k)
{
    Node *temp = head;
    int cnt = 1;
    if (k <= 0)
        return head;
    while (temp != nullptr && cnt <= k - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr)
        return head;
    if (k == 1)
    {
        Node *newhead = head->next;
        if (newhead != nullptr)
            newhead->back = nullptr;
        head->next = nullptr;
        delete head;
        return newhead;
    }
    else
    {
        Node *delnode = temp;
        Node *front = temp->next;
        Node *prev = temp->back;
        prev->next = front;
        if (front != nullptr)
            front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        delete delnode;
        return head;
    }
}
Node *deleteval(Node *head, int ele)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == ele)
        {
            if (temp == head)
            {
                Node *newhead = head->next;
                if (newhead != nullptr)
                    newhead->back = nullptr;
                head->next = nullptr;
                delete head;
                return newhead;
            }
            else
            {
                Node *delnode = temp;
                Node *front = temp->next;
                Node *prev = temp->back;
                prev->next = front;
                if (front != nullptr)
                    front->back = prev;
                temp->next = nullptr;
                temp->back = nullptr;
                delete delnode;
                return head;
            }
        }
        temp=temp->next;
    }
}
Node* inserthead(Node* head,int val)
{
    Node* newhead=new Node(val,head,nullptr);
    if(head)
    head->back=newhead;
    return newhead;
}
Node* inserttail(Node* head,int val)
{
    if(head==nullptr)
    return new Node(val);
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    Node* newtail=new Node(val,nullptr,temp);
    temp->next=newtail;
    return head;
}
Node* insertkele(Node* head,int val,int k)
{
int cnt=1;
if(k==1)
{   
    Node* newhead=new Node(val,head,nullptr);
    if(head)
    head->back=newhead;
    return newhead;
}
else
{
Node* temp=head;
while(temp!=nullptr && cnt<k-1)
{
    temp=temp->next;
    cnt++;
}
if(temp==nullptr)
return head;
else if(temp->next==nullptr)
{
    Node* newtail=new Node(val,nullptr,temp);
    temp->next=newtail;
    return head;
}
else
{
Node* front=temp->next;
Node* newnode= new Node(val,front,temp);
front->back=newnode;
temp->next=newnode;
return head;
}
}
}
Node* insertval(Node* head,int val,int k)
{
    if(head==nullptr)
    return new Node(val);
    else if(head->data==k)
    {
    Node* newhead=new Node(val,head,nullptr);
    head->back=newhead;
    return newhead;
    }
    else
    {
        Node* temp=head;
        while(temp!=nullptr)
        {
            if(temp->data==k)
            {
                Node* prev=temp->back;
                Node* newnode=new Node(val,temp,prev);
                temp->back=newnode;
                prev->next=newnode;
                return head;
            }
            temp=temp->next;
        }
    }
    return head;
}
void searchele(Node* head,int val)
{
    while (head != nullptr)
    {
        if(head->data==val)
        {
        cout<<"Element is found"<<endl;
        return;
        }
        head=head->next;
    }
    cout<<"Element is not found"<<endl;
}
int main()
{
    vector<int> a = {2, 5, 8, 7};
    Node *head = convert2dll(a);
    printll(head);
    head=deletehead(head);
    printll(head);
    head=deletetail(head);
    printll(head);
    int k;
    cout << "Enter kth position to be deleted" << endl;
    cin >> k;
    head = deletekele(head, k);
    printll(head);
    int ele;
    cout << "Enter element to be deleted" << endl;
    cin >> ele;
    head = deleteval(head, ele);
    printll(head);
    head=inserthead(head,9);
    printll(head);
    head=inserttail(head,6);
    printll(head);
    head=insertkele(head,3,5);
    printll(head);
    head=insertval(head,1,3);
    printll(head);
    searchele(head,5);
    return 0;
}
//TC-O(N)/SC-O(1)
*/

//FOR CIRCULAR LINKED LIST
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
public:
Node(int data1,Node* next1)
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

Node* convert2cll(vector<int>&a)
{
    if(a.empty())
    {
        return nullptr;
    }
    Node* head=new Node(a[0]);
    Node* prev=head;
    for(int i=1;i<a.size();i++)
    {
        Node* temp=new Node(a[i]);
        prev->next=temp;
        prev=temp;
    }
    prev->next=head;
    return head;
}

void printll(Node* head)
{
    if(head==nullptr)
    {
        cout<<endl;
        return;
    }
    Node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

Node* deletehead(Node* head)
{
    if(head==nullptr)
    {
        return nullptr;
    }
    if(head->next==head)
    {
        delete head;
        return nullptr;
    }
    Node* tail=head;
    while(tail->next!=head)
    {
        tail=tail->next;
    }
    Node* newhead=head->next;
    tail->next=newhead;
    delete head;
    return newhead;
}

Node* deletetail(Node* head)
{
    if(head==nullptr)
    {
        return nullptr;
    }
    if(head->next==head)
    {
        delete head;
        return nullptr;
    }
    Node* tail=head;
    Node* prev=nullptr;
    while(tail->next!=head)
    {
        prev=tail;
        tail=tail->next;
    }
    prev->next=head;
    delete tail;
    return head;
}

Node* deletekele(Node* head,int k)
{
    if(head==nullptr||k<=0)
    {
        return head;
    }
    if(k==1)
    {
        return deletehead(head);
    }
    Node* curr=head;
    Node* prev=nullptr;
    int cnt=1;
    do
    {
        if(cnt==k)
        {
            if(curr->next==head)
            {
                return deletetail(head);
            }
            prev->next=curr->next;
            delete curr;
            return head;
        }
        prev=curr;
        curr=curr->next;
        cnt++;
    }while(curr!=head);
    return head;
}

Node* deleteval(Node* head,int ele)
{
    if(head==nullptr)
    {
        return nullptr;
    }
    if(head->data==ele)
    {
        return deletehead(head);
    }
    Node* curr=head->next;
    Node* prev=head;
    while(curr!=head)
    {
        if(curr->data==ele)
        {
            prev->next=curr->next;
            delete curr;
            return head;
        }
        prev=curr;
        curr=curr->next;
    }
    return head;
}

Node* inserthead(Node* head,int val)
{
    Node* newnode=new Node(val);
    if(head==nullptr)
    {
        newnode->next=newnode;
        return newnode;
    }
    Node* tail=head;
    while(tail->next!=head)
    {
        tail=tail->next;
    }
    newnode->next=head;
    tail->next=newnode;
    return newnode;
}

Node* inserttail(Node* head,int val)
{
    if(head==nullptr)
    {
        return inserthead(head,val);
    }
    Node* newnode=new Node(val);
    Node* tail=head;
    while(tail->next!=head)
    {
        tail=tail->next;
    }
    newnode->next=head;
    tail->next=newnode;
    return head;
}

Node* insertkele(Node* head,int val,int k)
{
    if(k==1)
    {
        return inserthead(head,val);
    }
    if(head==nullptr)
    {
        return nullptr;
    }
    Node* curr=head;
    int cnt=1;
    do
    {
        if(cnt==k-1)
        {
            Node* newnode=new Node(val,curr->next);
            curr->next=newnode;
            return head;
        }
        curr=curr->next;
        cnt++;
    }while(curr!=head);
    return head;
}

Node* insertval(Node* head,int val,int k)
{
    if(head==nullptr)
    {
        return nullptr;
    }
    if(head->data==k)
    {
        return inserthead(head,val);
    }
    Node* curr=head->next;
    Node* prev=head;
    do
    {
        if(curr->data==k)
        {
            Node* newnode=new Node(val,curr);
            prev->next=newnode;
            return head;
        }
        prev=curr;
        curr=curr->next;
    }while(curr!=head);
    return head;
}

void searchele(Node* head,int val)
{
    if(head==nullptr)
    {
        cout<<"Element is not found"<<endl;
        return;
    }
    Node* temp=head;
    do
    {
        if(temp->data==val)
        {
            cout<<"Element is found"<<endl;
            return;
        }
        temp=temp->next;
    }while(temp!=head);
    cout<<"Element is not found"<<endl;
}

int main()
{
    vector<int>a={2,5,8,7};
    Node* head=convert2cll(a);
    
    printll(head);
    head=deletehead(head);
    printll(head);
    head=deletetail(head);
    printll(head);
    
    int k_del;
    cout<<"Enter kth position to be deleted"<<endl;
    cin>>k_del;
    head=deletekele(head,k_del);
    printll(head);
    
    int ele_del;
    cout<<"Enter element to be deleted"<<endl;
    cin>>ele_del;
    head=deleteval(head,ele_del);
    printll(head);
    
    head=inserthead(head,9);
    printll(head);
    head=inserttail(head,6);
    printll(head);
    
    int k_ins;
    cout<<"Enter kth position to insert 3"<<endl;
    cin>>k_ins;
    head=insertkele(head,3,k_ins);
    printll(head);
    
    int val_ins;
    cout<<"Enter value k to insert 1 before"<<endl;
    cin>>val_ins;
    head=insertval(head,1,val_ins);
    printll(head);
    
    searchele(head,5);
    searchele(head,10);
    
    return 0;
}
//TC-O(N)/SC-O(1)
    */

//Q2 PRINTING A CLL
/*
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
public:
Node(int data1,Node* next1)
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
void printcll(Node* head)
{
if(head==nullptr)
{
    cout<<endl;
    return;
}
Node* temp=head;
do
{
    cout<<temp->data<<" ";
    temp=temp->next;
}while(temp!=head);
cout<<head->data<<" ";
}
int main()
{
    Node* head=new Node(2);
    head->next=new Node(5);
    head->next->next=new Node(6);
    head->next->next->next=head;
    printcll(head);
    return 0;
}
//TC-O(n)/SC-O(1)
*/

//Q3 SIZE OF CLL AND DLL
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node* prev;
Node(int data1)
{
    data=data1;
    next=nullptr;
    prev=nullptr;
}
};

int sizeDLL(Node* head)
{
    int count=0;
    Node* temp=head;
    while(temp!=nullptr)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

int sizeCLL(Node* head)
{
    if(head==nullptr)
    {
        return 0;
    }
    int count=0;
    Node* temp=head;
    do
    {
        count++;
        temp=temp->next;
    }while(temp!=head);
    return count;
}

int main()
{
    Node* headD=new Node(10);
    headD->next=new Node(20);
    headD->next->prev=headD;
    headD->next->next=new Node(30);
    headD->next->next->prev=headD->next;
    
    cout<<"SizeofDLL: "<<sizeDLL(headD)<<endl;

    Node* headC=new Node(2);
    headC->next=new Node(5);
    headC->next->next=new Node(6);
    headC->next->next->next=headC;
    
    cout<<"SizeofCLL: "<<sizeCLL(headC)<<endl;

    return 0;
}
//TC-O(n)/SC-O(1)
*/

//Q4 TO CHECK IF A DLL IS PALINDROME
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node* prev;
Node(int data1)
{
    data=data1;
    next=nullptr;
    prev=nullptr;
}
};
bool isPalindrome(Node* head)
{
    if(head==nullptr || head->next==nullptr)
    return true;
    Node* left=head;
    Node* right=head;
    while(right->next!=nullptr)
    {
        right=right->next;
    }
    while(left!=right && left->prev!=right)
    {
        if(left->data!=right->data)
        {
            return false;
        }
        left=left->next;
        right=right->prev;
    }
    return true;
}
int main()
{
    Node* headD=new Node(10);
    headD->next=new Node(20);
    headD->next->prev=headD;
    headD->next->next=new Node(30);
    headD->next->next->prev=headD->next;
    
    cout<<"Is the DLL Palindrome? : "<<isPalindrome(headD)<<endl;

    return 0;
}
//TC-O(n)/SC-O(1)
*/

//Q5 DETECTING LOOP IN LL
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node(int data1,Node* next1)
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
bool detect(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return true;
    }
    return false;
}
int main()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; 

    if (detect(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
    return 0;
}
//TC-O(n)/SC-O(1)
    */
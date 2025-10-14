//Q1 OPERATIONS ON A SINGLY LINKEDLIST
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
Node* convertll(vector<int>&a)
{
    Node *head=new Node(a[0]);
    Node *mover=head;
    for(int i=1;i<a.size();i++)
    {
        Node* temp=new Node(a[i]); //temp is being assigned the value of next immediate new node
        mover->next=temp; //mover pointing to next which is temp
        mover=temp; //shifting mover position to temp for next iteration
    }
    return head;
}
int checkifpresent(Node *head,int val) //TC-O(N)-WC/O(1)-BC,AC-O(N/2)
{
    Node* temp=head;
    while(temp)
    {
        if(temp->data==val)
        return 1;
        temp=temp->next;
    }
    return 0;
}
    Node *removehead(Node *head)
{
    if(head==NULL)
    return head;
    Node* temp=head;
    head=head->next; //pointing to next head
    delete temp;
    return head;
}
Node *removetail(Node *head)
{
    if(head==NULL || head->next==NULL)
    return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL) //for checking second last element
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
    oid printLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *deletek(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    Node *prevn = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prevn->next = prevn->next->next; // skipping the kth pointer
            free(temp);
            break;
        }
        prevn = temp;
        temp = temp->next;
    }
    return head;
}
Node *deleteel(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (head->data == k)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prevn = NULL;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            prevn->next = prevn->next->next; // skipping the kth pointer
            free(temp);
            break;
        }
        prevn = temp;
        temp = temp->next;
    }
    return head;
}
Node *inserthead(Node *head, int val) // inserting head
{
    return new Node(val, head);
}
Node *inserttail(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newnode = new Node(val);
    temp->next = newnode;
    return head;
}
Node *insertk(Node *head, int k, int val) //inserting at kth position
{
    int cnt = 1;
    if (head == NULL)
    {
        if (k == 1)
            return new Node(val, head);
        else
            return head;
    }
    Node *temp = head;
    while (temp != NULL && cnt < k - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL)
        return head;
    Node *newnode = new Node(val, temp->next); // initialization to kth node pointer
    temp->next = newnode;                      // kth  pointer pointing to newnode linking it to (k-1)th node
    return head;
}
Node *insertbeforevalue(Node *head, int k, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == k)
        return new Node(val, head); //as at very next position element has to be inserted
    Node *temp = head;
    bool found=false;
    while (temp->next != NULL)
    {
        if (temp->next->data == k)
        {
            Node *newnode = new Node(val, temp->next); // initialization to kth node pointer
            temp->next = newnode;                      // kth  pointer pointing to newnode linking it to (k-1)th node
            found=true;
            break;
        }
        temp=temp->next;
    }
    if(found==false)
    {
    cout<<"Value not found"<<endl;
    }
    return head;
}
int main()
{
    vector<int> a = {2, 5, 8, 7};
    Node *head = convertll(a);
    head = inserthead(head, 100);
    head = deleteel(head, 8);
    head = inserttail(head, 6);
    head = insertk(head, 2, 9);
    head = insertbeforevalue(head, 7, 22);
    printLL(head);
}
//TC/SC-O(1)
*/

//Q2 COUNT AND DELETE 
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

void printll(Node* head)
    {
        Node* temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

Node* delKey(Node* head,int key,int &count) 
{
    while (head && head->data == key) 
    {
        Node* temp=head;
        head=head->next;
        delete temp;
        count++;
    }
    Node* curr = head;
    while (curr && curr->next) 
    {
        if (curr->next->data == key) 
        {
            Node* temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
            count++;
        } 
        else 
        curr = curr->next;
    }
    return head;
}

int main() 
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printll(head);

    int key=1, count=0;
    head = delKey(head, key, count);

    cout << "Count: "<<count<<endl;
    cout << "Updated Linked List: "<<endl;
    printll(head);

    return 0;
}
//TC-O(N),SC-O(1)
    */

//Q3 FINDING MIDDLE ELEMENT
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
Node* midele(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* middleNode = midele(head);

    cout << "The middle node value is: " << middleNode->data << endl;
    return 0;
}
//TC-O(N/2),SC-O(1)
    */

//Q4 REVERSING A LINKEDLIST
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
Node *reversell(Node* head)
    {
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL)
        {
            Node* front=temp->next; //storing reference of next iteration
            temp->next=prev; //referencing to previous(linking backwards)
            prev=temp; //moving prev forward
            temp=front; //moving temp forward
        }
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
    }
int main()
{
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    cout << "Original Linked List: ";
    printll(head);

    head = reversell(head);

    cout << "\nReversed Linked List: ";
    printll(head);
    return 0;
}
//TC-O(N),SC-O(1)
    */
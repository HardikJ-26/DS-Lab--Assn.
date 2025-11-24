//Q1 SPLIT A CIRCULAR LL
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node* prev;
Node(int data1,Node* next1,Node* prev1)
{
    data=data1;
    next=next1;
    prev=prev1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
    prev=nullptr;
}
};
pair<Node*,Node*>splithead(Node* head)
{
Node *slow = head; 
Node *fast = head; 
    
if(head == nullptr) 
return {nullptr, nullptr}; 

while(fast->next != head && fast->next->next != head) 
{ 
    fast = fast->next->next; 
    slow = slow->next; 
}
if(fast->next->next == head) 
fast = fast->next;
Node* head1=head;
Node* head2=slow->next;
fast->next=slow->next;
slow->next=head;
return {head1,head2};
}
void printList(Node *head) 
{ 
    Node *curr = head; 
    if(head != nullptr) 
    { 
    do 
    { 
    cout << curr->data << " "; 
    curr = curr->next; 
    } while(curr != head); 
    cout << endl; 
    } 
} 
int main() { 
    
    Node *head = new Node(1); 
    Node *head1 = nullptr; 
    Node *head2 = nullptr; 

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    
    pair<Node*, Node*> result = splithead(head); 
    head1 = result.first;
    head2 = result.second;
    
    printList(head1); 
    printList(head2);
    
    return 0; 
}
//TC-O(n)/SC-O(1)
    */

//Q2 DELETE EVEN PARITY ELEMENTS
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node* prev;
Node(int data1,Node* next1,Node* prev1)
{
    data=data1;
    next=next1;
    prev=prev1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
    prev=nullptr;
}
};
bool isEvenParity(int x)
{
    int parity = 0;
    while (x != 0) {
        if (x & 1)
        parity++;
        x = x >> 1; //to discard rightmost bit
    }
    if (parity % 2 == 0)
        return true;
    else
        return false;
}
Node* removedll(Node* head)
{
    Node* curr = head;
    while(curr)
    {
    Node* nextNode = curr->next;
    if(isEvenParity(curr->data))
    {
        if(curr == head)
        {
            head = head->next;
            if(head) head->prev = nullptr;
        }
        else
        {
            curr->prev->next = curr->next;
            if(curr->next)
            curr->next->prev = curr->prev;
        }
        delete curr;
    }
    curr = nextNode;
    }
    return head;
}
Node* removecll(Node* head)
{
if(!head) return head;
Node* curr = head;
do 
{
    Node* nextNode = curr->next;

    if(isEvenParity(curr->data))
    {
    if(curr == head)
    {
        if(head->next == head)
        {
            delete head;
            return nullptr;
        }
        head = head->next;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    }
    curr = nextNode;
} 
while(curr != head);
return head;
}
void printDLL(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void printCSLL(Node* head)
{
    if(!head)
    {
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
int main()
{
    Node* headD=new Node(3);
    headD->next=new Node(5);
    headD->next->prev=headD;
    headD->next->next=new Node(6);
    headD->next->next->prev=headD->next;
    
    cout<<"DLL Before:"<<endl;
    printDLL(headD);
    headD=removedll(headD);
    cout<<"DLL After:"<<endl;
    printDLL(headD);

    Node* headC=new Node(3);
    headC->next=new Node(5);
    headC->next->next=new Node(6);
    headC->next->next->next=headC;

    cout<<"CSLL Before:"<<endl;
    printCSLL(headC);
    headC=removecll(headC);
    cout<<"CSLL After:"<<endl;
    printCSLL(headC);
    return 0;
}
//TC/SC-O(n)
*/
//Q3 REVERSE EVERY K NODES
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node* prev;
Node(int data1,Node* next1,Node* prev1)
{
    data=data1;
    next=next1;
    prev=prev1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
    prev=nullptr;
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
Node* reversell(Node* head) 
{
    Node* temp=head;
    Node* last=NULL;
    while(temp)
    {
        last=temp->prev;
        temp->prev=temp->next;
        temp->next=last;
        temp=temp->prev;
    }
    if(last!=NULL)
    {
        return last->prev;
    }
    return head;
}
Node* getkthnode(Node *temp,int k)
{
    k-=1;
    while(temp!=NULL && k>0)
    {
        k--;
        temp=temp->next;
    }
    return temp;
}
Node* kreverse(Node* head,int k)
{
    Node* temp=head;
    Node* prevlast=NULL;
    while(temp)
    {
        Node* kthnode=getkthnode(temp,k);
        if(kthnode==NULL) 
        {
            if(prevlast) 
            {
                prevlast->next=temp;
                temp->prev=prevlast;
            }
            break;
        }
        Node* nextnode=kthnode->next;
        kthnode->next=NULL; 
        temp->prev=NULL; 
        reversell(temp);
        if(temp==head)
        {
            head=kthnode;
            kthnode->prev=NULL;
        }
        else
        {
            prevlast->next=kthnode;
            kthnode->prev=prevlast;
        }
        prevlast=temp;
        temp=nextnode;
    }
    return head;
}
int main()
{
    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->prev = head;
    
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    cout<<"Original list is "<<endl;
    printll(head);
    int k=2;
    head =  kreverse(head,k);

    cout << "\nK reversed list is : " << endl;
    printll(head);
    return 0;
}
    */

//Q4 CORRECT RANDOM POINTER IN DLL
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node* prev;
Node(int data1,Node* next1,Node* prev1)
{
    data=data1;
    next=next1;
    prev=prev1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
    prev=nullptr;
}
};

Node* correct(Node* head)
{
    if (head == nullptr) return nullptr;
    head->prev = nullptr;
    Node* temp = head;
    while(temp->next != nullptr)
    {
    if(temp->next->prev != temp)
    {
        temp->next->prev = temp;
    }
    temp = temp->next;
    }
    return head;
}

void printll(Node *head)
{
    Node *temp = head;
    int limit = 0; 
    while (temp != nullptr && limit < 20)
    {
        cout << temp->data << " ";
        temp = temp->next;
        limit++;
    }
    if(limit >= 20) cout << "...(cycle/truncated)";
    cout << endl;
}

int main()
{
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    head->next = n2;
    n2->prev = head;
    Node* n3 = new Node(3);
    n2->next = n3; 
    n3->prev = head; 
    n3->next = nullptr;

    cout << "Incorrect linked list (Backward checks would fail): " << endl;
    printll(head);
    head = correct(head);
    cout << "Corrected linked list: " << endl;
    printll(head);
    
    return 0;
}
//TC-O(N)/SC-O(1)
    */

//Q5 TRANSFORM 2D MATRIX INTO DLL
/*
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* back;
    Node* up;
    Node* down;

    Node(int data1,Node* next1,Node* back1,Node* up1,Node* down1)
    {
        data=data1;
        next=next1;
        back=back1;
        up=up1;
        down=down1;
    }
    Node(int data1)
    {
        data=data1;
        next=nullptr;
        back=nullptr;
        up=nullptr;
        down=nullptr;
    }
};

void print(Node* head)
{
    Node* downptr=head;
    Node* rightptr;
    while(downptr)
    {
        rightptr=downptr;
        while(rightptr)
        {
            cout<<(rightptr->data)<<" ";
            rightptr=rightptr->next;
        }
        cout<<"\n";
        downptr=downptr->down;
    }
}

Node* transfrommatrix(int mat[3][3])
{
    int n=3,m=3;
    Node* head_main=NULL;
    Node* upper_row_head=NULL;

    for(int i=0;i<n;i++)
    {
        Node* headrow=NULL;
        Node* prev=NULL;
        Node* upper=upper_row_head;

        for(int j=0;j<m;j++)
        {
            Node* temp=new Node(mat[i][j]);

            if(i==0 && j==0)
            {
                head_main=temp;
            }
            if(j==0)
            {
                headrow=temp;
            }
            if(prev)
            {
                prev->next=temp;
                temp->back=prev;
            }
            prev=temp;
            if(upper)
            {
                temp->up=upper;
                upper->down=temp;
                upper=upper->next;
            }
        }
        upper_row_head=headrow;
    }
    return head_main;
}
int main()
{
    int mat[3][3]=
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Node* head_main=transfrommatrix(mat);
    print(head_main);
    return 0;
}
//TC-O(N*N)/SC-O(1)
*/
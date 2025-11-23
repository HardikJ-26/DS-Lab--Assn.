//Q1A PRE-ORDER TRAVERSAL
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* ryt;
Node(int data)
{
    val=data;
    left=nullptr;
    ryt=nullptr;
}
};
void preorder(Node* root,vector<int>&a)
{
    if(root==nullptr)
    return;
    a.push_back(root->val);
    preorder(root->left,a); //recursively traverse the left subtree
    preorder(root->ryt,a); //recursively traverse the ryt subtree
}
vector<int>preOrder(Node* root)
{
    vector<int>a;
    preorder(root,a);
    return a;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    vector<int> result = preOrder(root);
    cout<<"Preorder traversal : ";
    for(int val:result)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//TC/SC-O(N)
*/
//Q1B INORDER TRAVERSAL
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* ryt;
Node(int data)
{
    val=data;
    left=nullptr;
    ryt=nullptr;
}
};
void inorder(Node* root,vector<int>&a)
{
    if(root==nullptr)
    return;
    inorder(root->left,a); //recursively traverse the left subtree
    a.push_back(root->val);
    inorder(root->ryt,a); //recursively traverse the ryt subtree
}
vector<int>inOrder(Node* root)
{
    vector<int>a;
    inorder(root,a);
    return a;
}
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    vector<int> result = inOrder(root);
    cout<<"Inorder traversal : ";
    for(int val:result)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q1C POST-ORDER TRAVERSAL
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* ryt;
Node(int data)
{
    val=data;
    left=nullptr;
    ryt=nullptr;
}
};
void postorder(Node* root,vector<int>&a)
{
    if(root==nullptr)
    return;
    postorder(root->left,a); //recursively traverse the left subtree
    postorder(root->ryt,a); //recursively traverse the ryt subtree
    a.push_back(root->val);
}
vector<int>postOrder(Node* root)
{
    vector<int>a;
    postorder(root,a);
    return a;
}
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    vector<int> result = postOrder(root);
    cout<<"Inorder traversal : ";
    for(int val:result)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q2A SEARCHING A GIVEN ITEM
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* ryt;
Node(int data)
{
    val=data;
    left=nullptr;
    ryt=nullptr;
}
};
bool preorder(Node* root,int target)
{   
    if(root==NULL)
    return false;
    if(root->val==target)
    return true;
    if(preorder(root->left,target)) //recursively traverse the left subtree
    return true;
    if(preorder(root->ryt,target)) //recursively traverse the ryt subtree
    return true;
    return false;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    int target=47;
    cout<<"Element is found : "<<preorder(root,target);
    return 0;
}
//TC-O(N)/SC-O(1)

    */

//Q2B&C MAXIMUM AND MINIMUM ELEMENT
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* ryt;
Node(int data)
{
    val=data;
    left=nullptr;
    ryt=nullptr;
}
};
pair<int,int> preorder(Node* root)
{   
    if(root==NULL)
    return {INT_MIN,INT_MAX};
    pair<int,int> left_result=preorder(root->left);
    pair<int,int> ryt_result=preorder(root->ryt);
    
    int maxi = root->val;
    int mini = root->val;

    maxi = max({maxi,left_result.first,ryt_result.first});
    mini = min({mini,left_result.second,ryt_result.second});

    return {maxi,mini};
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    pair<int,int>result=preorder(root);
    cout<<"Maximum element is "<<result.first<<endl;
    cout<<"Minimum element is "<<result.second<<endl;
    
    return 0;
}
//TC-O(N)/SC-O(1)
    */

//Q2D&E INORDER SUCCESSOR AND PREDECESSOR OF A NODE IN BST
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
Node* insuccessor(Node* root,Node* key)
{
    Node* successor=nullptr;
    while(root)
    {
        if(key->val>=root->val)
        root=root->right;
        else
        {
            successor=root;
            root=root->left;
        }
    }
    return successor;
}
Node* inpredecessor(Node* root,Node* key)
{
    Node* predecessor=nullptr;
    while(root)
    {
        if(key->val>root->val)
        {
        predecessor=root;
        root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return predecessor;
}
void printInOrder(Node* root) 
{
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() 
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    cout << "BST: ";
    printInOrder(root);
    cout << endl;

    Node* p = root->left->right;

    Node* successor = insuccessor(root, p);
    Node* predecessor=inpredecessor(root,p);

    if (successor != nullptr) 
    {
        cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    } 
    else 
    {
        cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    }
    if (successor != nullptr) 
    {
        cout << "Inorder Predecessor of " << p->val << " is: " << predecessor->val << endl;
    } 
    else 
    {
        cout << "Inorder Predecessor of " << p->val << " does not exist." << endl;
    }
    return 0;
}
//TC-O(N)/SC-O(1)
    */

//Q3A INSERTING AN ELEMENT
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
Node* insertbst(Node* root,int key)
{
    if(!root)
    return new Node(key);
    Node* curn=root;
    while(true)
    {
        if(curn->val<=key)
        {
            if(curn->right!=NULL)
            curn=curn->right;
            else
            {
                curn->right=new Node(key);
                break;
            }
        }
        else
        {
            if(curn->left!=NULL)
            curn=curn->left;
            else
            {
                curn->left=new Node(key);
                break;
            }
        }
    }
    return root;
}
void printinOrder(Node* root) 
{
    if (root == nullptr) 
    return;

    printinOrder(root->left);

    cout << root->val << " ";

    printinOrder(root->right);
}
int main() 
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    
    cout << "Binary Search Tree: "<< endl;
    printinOrder(root);
    cout << endl;
    
    // Searching for a value in the BST
    int target = 8;
    Node* ref=insertbst(root,target);
    
    cout << "Binary Search Tree after Insertion: "<< endl;
    printinOrder(ref);
    cout << endl;
    
    return 0;
}
//TC-O(logN),SC-O(1)
*/

//Q3B DELETION IN BST
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
Node* findlastright(Node* root)
{
    if(!root->right)
    return root;
    findlastright(root->right);
}
Node* helper(Node* root)
{
    if(root->left==NULL)
    return root->right;
    else if(root->right)
    return root->left;
    Node* rightchild=root->right;
    Node* lastright=findlastright(root->left);
    lastright->right=rightchild;
}
Node*  deletenode(Node* root,int key)
{
if(!root)
return NULL;
if(root->val==key)
return helper(root);
Node* dummynode=root;
while(root!=NULL)
{
    if(root->val>key)
    {
        if(root->left!=NULL && root->left->val==key)
        {
        root->left=helper(root->left);
        break;
        }
        else
        {
           root=root->left; 
        }
    }
    else
    {
        if(root->right!=NULL && root->right->val==key)
        {
            root->right=helper(root->right);
            break;
        }
        else
        {
           root=root->right; 
        }
    }
}
return dummynode;
}
void printinOrder(Node* root) 
{
    if (root == nullptr) 
    return;

    printinOrder(root->left);

    cout << root->val << " ";

    printinOrder(root->right);
}
int main() 
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    
    cout << "Binary Search Tree: "<< endl;
    printinOrder(root);
    cout << endl;
    int key=6;
    root=deletenode(root,key);
    cout << "Binary Search Tree after deletion : "<< endl;
    printinOrder(root);
    cout << endl;
    return 0;
}
//TC-O(logN),SC-O(1)
*/

//Q3C&D MAXIMUM AND MINIMUM DEPTH IN A BST
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* ryt;
Node(int data)
{
    val=data;
    left=nullptr;
    ryt=nullptr;
}
};

int maxDepth(Node* root)
{
    if(root==nullptr)
        return 0;
    
    return 1+max(maxDepth(root->left),maxDepth(root->ryt));
}

int minDepth(Node* root)
{
    if(root==nullptr)
        return 0;

    if(root->left==nullptr && root->ryt==nullptr)
        return 1;

    if(root->left==nullptr)
        return 1+minDepth(root->ryt);
        
    if(root->ryt==nullptr)
        return 1+minDepth(root->left);

    return 1+min(minDepth(root->left),minDepth(root->ryt));
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->ryt = new Node(8);
    root->left->left = new Node(1);
    root->left->ryt = new Node(4);
    root->ryt->ryt = new Node(10);
    
    cout<<"Maximum depth is "<<maxDepth(root)<<endl;
    cout<<"Minimum depth is "<<minDepth(root)<<endl;
    
    return 0;
}
    */

//Q4 CHECK IF TREE IS BT OR BST
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
bool isvalidbst(Node* root,int min,int max)
{
    if(!root)
    return true;
    if(root->val>=max || root->val<=min)
    return false;
    return isvalidbst(root->left,min,root->val) && isvalidbst(root->right,root->val,max); 
    //bcause we update interval acc to val while going left and ryt
}
bool isbst(Node* root)
{
    return isvalidbst(root,INT_MIN,INT_MAX);
}
int main() 
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    
    cout << "Binary Search Tree is Valid : "<<isbst(root)<< endl;

    return 0;
}
//TC-O(N)/SC-O(1)
*/

//Q5 HEAPSORT
/*
#include <bits/stdc++.h>
using namespace std;

class Heaps
{
public:
int capacity;
int size;
int *a;
Heaps(int cap)
{
capacity=cap;
size=0;
a=new int[capacity];
}
int parent(int i)
{
return (i-1)/2;
}
int left(int i)
{
    return (2*i+1);
}
int right(int i)
{
    return (2*i+2);
}
void Insert(int i)
{
    if(size==capacity)
    {
    cout<<"Heap size Overflow";
    return;
    }
    a[size]=i;
    int k=size;
    size++;
    //fixing minheap property
    while(k!=0 && a[parent(k)]>a[k])
    {
    swap(a[parent(k)],a[k]);
    k=parent(k);
    }
}
void HeapifyDown(int root)
{
    int ryt=right(root);
    int lef=left(root);
    int mini=root;
    if(lef<size && a[lef]<a[mini])
    mini=lef;
    if(ryt<size && a[ryt]<a[mini])
    mini=ryt;
    if(mini!=root)
    {
    swap(a[mini],a[root]);
    HeapifyDown(mini);
    }
}
void HeapifyUp(int k)
{
    while(k!=0 && a[parent(k)]>a[k])
    {
    swap(a[parent(k)],a[k]);
    k=parent(k);
    }
}
void print() 
{
    for (int i = 0; i < size; i++)
    cout << a[i] << " ";
    cout << endl;
}
};
int main()
{
    Heaps h(20);
    h.Insert(4);
    h.Insert(9);
    h.Insert(2);
    h.Insert(3);

    HeapifyDown();
    h.Insert(7);
    h.Insert(3);
    h.Insert(6);
    h.Insert(5);
    
    HeapifyUp();
    return 0;
}
*/
//TC/SC-O(N)

//Q6 IMPLEMENT PRIORITY QUEUES USING HEAPS
/*
#include <bits/stdc++.h>
using namespace std;

class MaxPriorityQueue{
private:
    vector<int> data;

    void HeapifyUp(int childIndex)
    {
        while(childIndex>0)
        {
            int parentIndex=(childIndex-1)/2;
            if(data[childIndex]>data[parentIndex])
            {
                swap(data[childIndex],data[parentIndex]);
                childIndex=parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void HeapifyDown(int parentIndex)
    {
        int heapSize=data.size();
        int largest=parentIndex;
        int left=2*parentIndex+1;
        int right=2*parentIndex+2;

        if(left<heapSize&&data[left]>data[largest]){
            largest=left;
        }

        if(right<heapSize&&data[right]>data[largest]){
            largest=right;
        }

        if(largest!=parentIndex){
            swap(data[parentIndex],data[largest]);
            HeapifyDown(largest);
        }
    }

public:
    bool isEmpty(){
        return data.empty();
    }
    
    void push(int value){
        data.push_back(value);
        HeapifyUp(data.size()-1);
    }

    int top(){
        if(isEmpty()){
            throw runtime_error("Queue is empty,can't peek");
        }
        return data[0];
    }

    int pop(){
        if(isEmpty()){
            throw runtime_error("Queue is empty,can't extract max");
        }
        int maxValue=data[0];
        data[0]=data.back();
        data.pop_back();
        if(!isEmpty()){
            HeapifyDown(0);
        }
        return maxValue;
    }
};

int main(){
    MaxPriorityQueue pq;
    
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(8);
    pq.push(15);
    
    cout<<"Maximum element (Top): "<<pq.top()<<endl; 
    
    cout<<"Popped element is "<<pq.pop()<<endl; 
    cout<<"Popped element is "<<pq.pop()<<endl;
    
    pq.push(30);
    
    cout<<"Maximum element (Top): "<<pq.top()<<endl;
    
    while(!pq.isEmpty()){
        cout<<"Popping: "<<pq.pop()<<endl;
    }
    
    return 0;
}
*/
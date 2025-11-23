//Q1 SUM OF ALL LEFT LEAVES
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int x)
{
    val=x;
    left=nullptr;
    right=nullptr;
}
};
int sumOfLeftLeaves(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    int sum=0;
    if(root->left!=nullptr)
    {
        if(root->left->left==nullptr && root->left->right==nullptr)
        {
            sum+=root->left->val;
        }
        else
        {
            sum+=sumOfLeftLeaves(root->left);
        }
    }
    sum+=sumOfLeftLeaves(root->right);
    return sum;
}

int main()
{
    
    Node* root=new Node(3);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);

    int result=sumOfLeftLeaves(root);
    
    cout<<"Sum of left leaves is: "<<result<<endl;

    return 0;
}
    */
//TC-(logN)/SC-O(1)

//Q2 FINDING UNIQUE BSTs
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int x)
{
    val=x;
    left=nullptr;
    right=nullptr;
}
};

vector<Node*> generatetree(int start,int end)
{
    if(start>end)
    {
        return {nullptr};
    }
    
    vector<Node*> result;

    for(int i=start;i<=end;++i)
    {
        vector<Node*> leftSubtrees=generatetree(start,i-1);
        vector<Node*> rightSubtrees=generatetree(i+1,end);

        for(Node* leftRoot:leftSubtrees)
        {
            for(Node* rightRoot:rightSubtrees)
            {
                Node* root=new Node(i);
                root->left=leftRoot;
                root->right=rightRoot;
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<Node*> generateTrees(int n)
{
    if(n==0)
    {
        return {};
    }
    return generatetree(1,n);
}
void printTree(Node* root)
{
    if(root==nullptr)
    {
        cout<<"null";
        return;
    }
    cout<<root->val;
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    int n=3;
    vector<Node*> trees=generateTrees(n);
    
    cout<<"Generated Trees are:"<<endl;
    for(Node* tree:trees)
    {
        printTree(tree);
        cout<<endl;
    }
    return 0;
}
//TC/SC-O(n)
*/

//Q3 MAXIMUM DEPTH/HEIGHT OF BT
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
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    ryt=rytt;
}
};
int maxdepth(Node* root)
{
    if(root==NULL)
    return 0;
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->ryt);
    return 1+max(lh,rh);
}
int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    root->left->ryt->ryt = new Node(6);
    root->left->ryt->ryt->ryt = new Node(7);
    
    int depth = maxdepth(root);
    cout << "Maximum depth of the binary tree: " << depth << endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q4 RIGHT/LEFT SIDE VIEW
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
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    ryt=rytt;
}
};
void recursionleft(Node* root,int level,vector<int>&res)
{
    if(root==NULL)
    return;
    if(res.size()==level)
    res.push_back(root->val);
    recursionleft(root->left,level+1,res);
    recursionleft(root->ryt,level+1,res);
}
void recursionryt(Node* root,int level,vector<int>&res)
{
    if(root==NULL)
    return;
    if(res.size()==level)
    res.push_back(root->val);
    recursionryt(root->ryt,level+1,res);
    recursionryt(root->left,level+1,res);
}
vector<int>leftsideview(Node* root)
{
    vector<int>res;
    recursionleft(root,0,res);
    return res;
}
vector<int>rytsideview(Node* root)
{
    vector<int>res;
    recursionryt(root,0,res);
    return res;
}
int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->ryt = new Node(10);
    root->left->left->ryt = new Node(5);
    root->left->left->ryt->ryt = new Node(6);
    root->ryt = new Node(3);
    root->ryt->ryt = new Node(10);
    root->ryt->left = new Node(9);

    vector<int> rightView = rytsideview(root);

    cout << "Right View Traversal: ";
    for(auto node: rightView)
    {
        cout << node << " ";
    }
    cout << endl;
    vector<int> leftView = leftsideview(root);

    cout << "Left View Traversal: ";
    for(auto node: leftView){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
//TC/SC-(logN)
    */

//Q5 CONSTRUCT BT WITH INORDER AND  PREORDER
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
Node* buildbt(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,map<int,int>inmap)
{
    if(prestart>preend || instart>inend)
    return NULL;
    Node* root=new Node(preorder[prestart]);
    int inroot=inmap[root->val];
    int numsleft=inroot-instart;
    root->left=buildbt(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,inmap);
    root->right=buildbt(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,inmap);
    return root;
}
Node* mapping(vector<int>& preorder,vector<int>&inorder)
{
    map<int,int>inMap;
    for(int i=0;i<inorder.size();i++)
    {
        inMap[inorder[i]]=i;
    }
    Node* root=buildbt(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
    return root;
}
void printLevelOrder(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}
int main() 
{
    vector<int>pre={3,9,6,20,15,7};
    vector<int>in={9,6,3,15,20,7};
    Node* root=mapping(pre,in);

    cout << "Tree built from preorder and inorder (Level-order):" << endl;
    printLevelOrder(root);
    return 0;
}
    */
//TC-O(logN * N),SC-O(N)

//Q6 CONSTRUCT BT WITH INORDER AND  POSTORDER
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
Node* buildbt(vector<int>&postorder,int poststart,int postend,vector<int>&inorder,int instart,int inend,map<int,int>inmap)
{
    if(poststart>postend || instart>inend)
    return NULL;
    Node* root=new Node(postorder[postend]);
    int inroot=inmap[root->val];
    int numsleft=inroot-instart;
    root->left=buildbt(postorder,poststart,poststart+numsleft-1,inorder,instart,inroot-1,inmap);
    root->right=buildbt(postorder,poststart+numsleft,postend-1,inorder,inroot+1,inend,inmap);
    return root;
}
Node* mapping(vector<int>& postorder,vector<int>&inorder)
{
    map<int,int>inMap;
    for(int i=0;i<inorder.size();i++)
    {
        inMap[inorder[i]]=i;
    }
    Node* root=buildbt(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inMap);
    return root;
}
void printLevelOrder(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}
int main() 
{
    vector<int> post = {6, 9, 15, 7, 20, 3};
    vector<int> in = {9, 6, 3, 15, 20, 7};
    Node* root=mapping(post,in);

    cout << "Tree built from postorder and inorder (Level-order):" << endl;
    printLevelOrder(root);
    return 0;
}
//TC-O(logN * N),SC-O(N)
    */

//Q7 MERGE BSTs INTO A DOUBLY LINKED LIST
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

Node* head=nullptr;
Node* tail=nullptr;

void convertToDLL(Node* root)
{
    if(!root)
    {
        return;
    }

    convertToDLL(root->left);

    if(head==nullptr)
    {
        head=root;
        tail=root;
    }
    else
    {
        tail->right=root;
        root->left=tail;
        tail=root;
    }
    root->left=nullptr;
    root->right=nullptr;
    convertToDLL(root->right);
}

Node* mergeDLLs(Node* head1,Node* head2)
{
    Node* dummy=new Node(0);
    Node* current=dummy;
    
    while(head1!=nullptr && head2!=nullptr)
    {
        if(head1->val<=head2->val)
        {
            current->right=head1;
            head1->left=current;
            head1=head1->right;
        }
        else
        {
            current->right=head2;
            head2->left=current;
            head2=head2->right;
        }
        current=current->right;
    }
    
    if(head1!=nullptr)
    {
        current->right=head1;
        head1->left=current;
    }
    
    if(head2!=nullptr)
    {
        current->right=head2;
        head2->left=current;
    }
    
    Node* mergedHead=dummy->right;
    if(mergedHead!=nullptr)
    {
        mergedHead->left=nullptr;
    }
    
    delete dummy;
    return mergedHead;
}

Node* mergebsts(Node* root1,Node* root2)
{
    head=nullptr;
    tail=nullptr;
    convertToDLL(root1);
    Node* head1=head;
    
    head=nullptr;
    tail=nullptr;
    convertToDLL(root2);
    Node* head2=head;
    
    return mergeDLLs(head1,head2);
}

int main()
{
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    Node* resultHead=mergebsts(root1,root2);
    
    Node* current=resultHead;
    while(current!=nullptr)
    {
        cout<<current->val<<" ";
        current=current->right;
    }
    cout<<endl;
    
    return 0;
}
//TC/SC-O(N)
*/
//Q1 SUM OF ALL LEFT LEAVES

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
int val;
TreeNode* left;
TreeNode* right;
TreeNode(int x)
{
    val=x;
    left=nullptr;
    right=nullptr;
}
};
int sumOfLeftLeaves(TreeNode* root)
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
    
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);

    int result=sumOfLeftLeaves(root);
    
    cout<<"Sum of left leaves is: "<<result<<endl;

    return 0;
}
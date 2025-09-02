//Q1 Previous Smaller Element
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>prevsmallerele(vector<int>&nums)
{
int n=nums.size();
vector<int>nge(n,-1);
stack<int>st;
for(int i=0;i<n;i++)
{
while(!st.empty() && st.top()>=nums[i])
{
    st.pop();
}
if(!st.empty())
nge[i]=st.top();
st.push(nums[i]);
}
return nge;
}
int main()
{
vector < int > v {5,7,1,2,6,0};
vector < int > res = prevsmallerele(v);
cout << "The next smaller elements are" << endl;
for (int i = 0; i < res.size(); i++) 
{
cout << res[i] << " ";
}
return 0;
}
//TC/SC-O(N)
*/

//Q2 MINSTACK
/*
#include <bits/stdc++.h>
using namespace std;

class minstack
{
    stack<int>st;
    int mini;
    public:
    minstack()
    {
        while(st.empty()==false)
        st.pop();
        mini=INT16_MAX;
    }
    void push(int val)
    {
        if(st.empty())
        {
            mini=val;
            st.push(val);
        }
        else
        {
            if(val<mini)
            {
            st.push(2*val-mini);
            mini=val;
            }
            else
            st.push(val);
        }
    }
    void pop()
    {
        if(st.empty())
        return;
        int val=st.top();
        st.pop();
        if(val<mini)
        {
            mini=(2*mini-val);
        }
    }
    int top()
    {
        if(st.empty())
        return -1;
        int val=st.top();
        if(val<mini)
        return mini;
        return val;
    }
    int getmin()
    {
        return mini;
    }
};
int main()
{
    minstack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout<<st.getmin()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.getmin()<<endl;
    return 0;
}
//TC-O(1) SC-O(N)
*/

//Q3 NEXT GREATER ELEMENT (MONOTONIC FORM) IN STACK
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>nextgreaterele(vector<int>&nums)
{
int n=nums.size();
vector<int>nge(n,-1);
stack<int>st;
for(int i=n-1;i>=0;i--)
{
while(!st.empty() && st.top()<=nums[i])
{
    st.pop();
}
if(!st.empty())
nge[i]=st.top();
st.push(nums[i]);
}
return nge;
}
int main()
{
vector < int > v {5,7,1,2,6,0};
vector < int > res = nextgreaterele(v);
cout << "The next greater elements are" << endl;
for (int i = 0; i < res.size(); i++) 
{
cout << res[i] << " ";
}
return 0;
}
//TC/SC-O(N)
*/

//Q4 Next Greater Temperature
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>nextgreaterele(vector<int>&nums)
{
int n=nums.size();
vector<int>ngt(n,0);
stack<int>st;
for(int i=n-1;i>=0;i--)
{
while(!st.empty() && nums[st.top()]<=nums[i])
{
    st.pop();
}
if(!st.empty())
ngt[i]=st.top()-i;
st.push(i);
}
return ngt;
}
int main()
{
vector < int > v = {25,17,11,22,16,50};
vector < int > res = nextgreaterele(v);
cout << "The next greater elements are" << endl;
for (int i = 0; i < res.size(); i++) 
{
cout << res[i] << " ";
}
return 0;
}
//TC/SC-O(N)
*/

//
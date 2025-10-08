//Q1 BINARY CONVERSION
/*
#include <bits/stdc++.h>
using namespace std;

vector<string>generatebinary(int n)
{
    vector<string>res;
    queue<string>q;
    q.push("1");
    while(n--)
    {
        string s1=q.front();
        q.pop();
        res.push_back(s1);
        q.push(s1+"0");
        q.push(s1+"1");
    }
    return res;
}
int main()
{
    int n = 6;
    vector<string>res=generatebinary(n);
    for (auto i : res) 
    {
        cout<<i<<" ";
    }
    cout << "\n";
    return 0;
}
TC/SC-O(N)
*/
//Q2 Sort Queue
/*
#include <bits/stdc++.h>
using namespace std;

int minindex(queue<int> &q,int sortedIndex)
{
    int mini=-1;
    int minv=INT_MAX;
    int n = q.size();
    for (int i=0;i<n;i++)
    {
        int curr=q.front();
        q.pop(); 

        if (curr<=minv && i<=sortedIndex)
        {
            mini=i;
            minv=curr;
        }
        q.push(curr);
    }
    return mini;
}

void rearrange(queue<int> &q,int mini)
{
    int minv;
    int n=q.size();
    for (int i = 0; i<n;i++)
    {
        int curr=q.front();
        q.pop();
        if (i!=mini)
            q.push(curr);
        else
            minv = curr;
    }
    q.push(minv);
}

void sortQueue(queue<int> &q)
{
    for (int i=1;i<=q.size();i++)
    {
        int mini=minindex(q,q.size()-i);
        rearrange(q,mini);
    }
}

int main()
{
  queue<int>q;
  q.push(30);
  q.push(11);
  q.push(15);
  q.push(4);
  sortQueue(q);
  
  while(q.empty()==false)
  {
     cout << q.front() << " ";
     q.pop();
  }
  cout << endl;
  return 0;
}
TC-O(N),SC-O(1)
  */

//Q3 CHECKING QUEUE IF SORTED
/*
#include <bits/stdc++.h>
using namespace std;

bool checkSorted(int n,queue<int>& q)
{
    stack<int> st;
    int nextnum=1;
    int front;

    while (!q.empty()) {
        front = q.front();
        q.pop();

        if (front==nextnum)
            nextnum++;
        else 
        {
            if (st.empty()) 
            {
                st.push(front);
            }
            else if (!st.empty() && st.top() < front) 
            {
                return false;
            }
            else
                st.push(front);
        }

        while (!st.empty() && st.top() == nextnum) {
            st.pop();
            nextnum++;
        }
    }
    if (nextnum-1==n && st.empty())
    return true;
    else
    return false;
}

int main()
{
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    int n = q.size();

    (checkSorted(n, q) ? (cout << "Yes") : (cout << "No"));
    return 0;
}
TC/SC-O(N)
    */

//Q4 STUDENT'S CAFETERIA
//Optimal Approach
/*
#include <bits/stdc++.h>
using namespace std;

int isServed(vector<int>&students,vector<int>&sandwiches)
{
int circlestudents=0;
int squarestudents=0;
for(int student : students)
{
    if(student==0)
    circlestudents++;
    else
    squarestudents++;
}
for(int sandwich : sandwiches)
{
  if(sandwich==0 && circlestudents==0)
  return squarestudents;
  if(sandwich==1 && squarestudents==0)
  return circlestudents;
  if(sandwich==0)
  circlestudents--;
  else
  squarestudents--;
}
return 0;
}
int main()
{
    vector<int>students={1,1,0,0};
    vector<int>sandwiches={0,1,0,1};
    cout<<"Result is "<<isServed(students,sandwiches)<<endl;
    return 0;
}
    */

//QUEUE APPROACH
/*
#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int>&students, vector<int>&sandwiches) 
{
    int len=students.size(); 
    queue<int>studentqueue;
    stack<int>sandwichstack;

    for (int i=0;i<len;i++) 
    {
        sandwichstack.push(sandwiches[len-i-1]);
        studentqueue.push(students[i]);
    }

    int served=0;
    while (!studentqueue.empty() && served<studentqueue.size()) 
    {
        if (sandwichstack.top() == studentqueue.front()) 
        {
            sandwichstack.pop();
            studentqueue.pop();
            served=0;
        } 
        else 
        {
            studentqueue.push(studentqueue.front());
            studentqueue.pop();
            served++;
        }
    }
    return studentqueue.size();
}
int main()
{
    vector<int>students={1,1,0,0};
    vector<int>sandwiches={0,1,0,1};
    cout<<"Result is "<<countStudents(students,sandwiches)<<endl;
    return 0;
}
TC-O(N),SC-O(1)
    */




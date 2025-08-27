//Extra Question 1
//Count Pairs with sum equal to k
/*
#include<bits/stdc++.h>
using namespace std;

int countpairs(vector<int>&a,int target)
{
    int n=a.size();
    int cnt=0;
    sort(a.begin(),a.end());
    int i=0,j=0;
    while(j<n)
    {
        if(a[j]-a[i]<target)
        j++;
        else if(a[j]-a[i]>target)
        i++;
        else
        {
            int ele1=a[i],ele2=a[j];
            int cnt1=0,cnt2=0;
            while(i<n && a[i]==ele1)
            {
                cnt1++;
                i++;
            }
            while(j<n && a[j]==ele2)
            {
                cnt2++;
                j++;
            }
            if(ele1==ele2)
            cnt+=(cnt1*(cnt1-1))/2;
            else
            cnt+=(cnt1*cnt2);
        }
    }
    return cnt;
}
int main()
{
    vector<int>a={1,4,1,5,4,8};
    int k=3;
    cout<<countpairs(a,k);
    return 0;
}
    */

//Extra Q2 String Split Challenge
/*
#include<bits/stdc++.h>
using namespace std;

bool sub(string major,string minor)
{
    return major.find(minor)!=string::npos;
}
bool cansplit(string s)
{
  int n=s.length();
  for(int i=0;i<n-2;i++)
  {
    for(int j=i+1;j<n-1;j++)
    {
        string a=s.substr(0,i+1);
        string b=s.substr(i+1,j-i);
        string c=s.substr(j+1);
        if(a.empty() || b.empty() || c.empty())
        continue;
        if((sub(b,a) && sub(c,a)) || (sub(a,c) && sub(b,c)) || (sub(a,b) && sub(c,b)))
        return true;
    }
  }
  return false;  
}
int main()
{
string s;
cout<<"Enter your string"<<endl;
cin>>s;
if(cansplit(s))
cout<<"YES,string can be split"<<endl;
else
cout<<"NO,string cannot be split"<<endl;
return 0;
}
*/

//EXTRA Q3 STRING ANAGRAMS
/*
#include<bits/stdc++.h>
using namespace std;

bool checkanagrams(string s1,string s2)
{
    if(s1.length()!=s2.length())
    return false;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1==s2;
}
int main()
{
    string str1="CAT";
    string str2="ABT";
    if(checkanagrams(str1,str2))
    cout<<"They are Anagrams"<<endl;
    else
    cout<<"They are not Anagrams"<<endl;
    return 0;
} 
    */

//Extra Q4 Dutch National Flag Algorithm
/*
#include<bits/stdc++.h>
using namespace std;

int sortarray(vector<int> &a,int n)
{
int low=0,mid=0,high=n-1;
while(mid<=high)
{
    if(a[mid]==0)
    {
        swap(a[low],a[mid]);
        low++;
        mid++;
    }
    else if(a[mid]==1)
    mid++;
    else
    {
        swap(a[mid],a[high]);
        high--;
    }
}
}
int main()
{   
    int n=6;
    vector<int>a={0, 2, 1, 2, 0, 1};
    sortarray(a,n);
    cout<<"After sorting-"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
    */

//Extra Question 5 Duplicate 2's
/*
#include<bits/stdc++.h>
using namespace std;

void duplicatetwos(int a[],int n)
{
int cnt=0;
for(int i=0;i<n;i++)
{
    if(a[i]==2)
    cnt++;
}
for(int i=n-1;i>=0;i--)
{
    if(a[i]==2)
    cnt--;
    int j=i+cnt; //edge cases(last ones)
    if(j<n) 
    a[j]=a[i];
    if(a[i]==2 && j+1<n) //middle cases
    a[j+1]=2;
}
for(int i=0;i<n;i++)
{
    cout<<a[i]<<" ";
}
}
int main()
{
    int a[]={1,0,2,4,0,2,5};
    int n=sizeof(a)/sizeof(a[0]);
    duplicatetwos(a,n);
    return 0;
}
    */
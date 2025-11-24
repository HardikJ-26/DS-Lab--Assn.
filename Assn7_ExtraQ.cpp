//Q1 MAJORITY ELEMENT (>N/2)
/*
#include<bits/stdc++.h>
using namespace std;

int majele(vector<int> v)
{
  int n=v.size();
  int cnt=0,el;
  for(int i=0;i<n;i++)
  {
    if(cnt==0)
    {
    el=v[i];
    cnt=1;
    }
    else if(v[i]==el)
    cnt++;
    else
    cnt--;
  } //till here we find the probable candidate but now have to check for majority(if it exists)
  cnt = 0;
  for(int i = 0; i < n; i++)
    {
        if(v[i] == el)
        cnt++;
    }
  if(cnt>n/2)
  return el;
  else
  return -1;
}

int main()
{
  int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout << "Majority element is " <<  majele(a) <<endl;
  return 0;
}
//TC-O(N)/SC-O(1)
*/

//Q2 TOP K FREQUENCY ITEMS
/*
#include<bits/stdc++.h>
using namespace std;

//using comparator to get descending order
bool compare(pair<int,int>&a,pair<int,int>&b)
{
    if(a.second!=b.second)
    {
        return a.second>b.second;
    }
    return a.first>b.first;
}

vector<int> topKFrequent(vector<int>&nums,int k)
{
    unordered_map<int,int>mp;
    for(int i:nums)
    {
        mp[i]++;
    }
    vector<pair<int,int>>v;
    for(auto it:mp)
    {
        v.push_back({it.first,it.second});
    }
    sort(v.begin(),v.end(),compare);
    vector<int>ans;
    for(int i=0;i<k;i++)
    {
        ans.push_back(v[i].first);
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter size of array:"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    }
    int k;
    cout<<"Enter k:"<<endl;
    cin>>k;
    vector<int>result=topKFrequent(arr,k);
    for(int i:result)
    {
    cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
//TC-O(N)/SC-O(N)
    */

//Q3 MAX SUM COMBINATIONS
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>maxcombinations(int n,int k,vector<int>&a,vector<int>&b)
{
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    vector<int>temp;
    int limit=n;
    if(k<n)
    {
        limit=n;
    }
    for(int i=0;i<limit;i++)
    {
        for(int j=0;j<limit;j++)
        {
            temp.push_back(a[i]+b[j]);
        }  
    }
    sort(temp.begin(),temp.end(),greater<int>());
    vector<int>ans;
    for(int i=0;i<k && i<temp.size();i++)
    {
        ans.push_back(temp[i]);
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter size of arrays:"<<endl;
    cin>>n;
    vector<int>a(n),b(n);
    cout<<"Enter elements of array A:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter elements of array B:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int k;
    cout<<"Enter k:"<<endl;
    cin>>k;
    vector<int>result=maxcombinations(n,k,a,b);
    for(int x:result)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
//TC-O(n*n)/SC-O(n)
*/

//Q4 EVEN-ODD SEPARATOR
/*
#include <bits/stdc++.h>
using namespace std;

void separator(vector<int>&a)
{
    vector<int>evenarr;
    vector<int>oddarr;
    for(auto i : a)
    {
        if(i%2==0)
        evenarr.push_back(i);
        else
        oddarr.push_back(i);
    }
    sort(evenarr.begin(),evenarr.end());
    sort(oddarr.begin(),oddarr.end(),greater<int>());
    int i = 0;
    for (int j = 0; j < evenarr.size(); j++)
    a[i++] = evenarr[j];
    for (int j = 0; j < oddarr.size(); j++)
    a[i++] = oddarr[j];
}
int main()
{
    vector<int> arr = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    separator(arr);
    cout<<"Sorted Order:- Even followed by Odd Numbers :"<<endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
//TC-O(N)/SC-O(N)
*/

//Q5 MAXIMUM ICECREAM BARS
/*
#include <bits/stdc++.h>
using namespace std;

int maxicecream(vector<int>&icecream,int coins)
{
    sort(icecream.begin(),icecream.end());
    int cnt=0;
    for(int i=0;i<icecream.size();i++)
    {
        if(icecream[i]>coins)
        break;
        cnt++;
        coins=coins-icecream[i];
    }
    return cnt;
}
int main()
{
    vector<int>costs={1,3,2,4,1};
    int coins=7;
    cout<<"Maximum number of icecreams that can be bought is : "<<maxicecream(costs,coins)<<endl;
    return 0;
}
//TC-O(logn)/SC-O(1)
*/
//Q1A SELECTION SORT
/*
#include<iostream>
using namespace std;

void select_sort(int a[],int n)
{
  for(int k=0;k<n-1;k++)
    {
      int temp;
      int min=k; //assumption for first checking
    for(int i=k+1;i<n;i++)
    {
      if(a[min]>a[i])
      {
        min=i;
      }
    }
        temp=a[min];
        a[min]=a[k];
        a[k]=temp;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    select_sort(a,n);
    for(int i=0;i<n;i++)
    {
       cout<<" "<<a[i];
    }
return 0;
}
*/


//Q1B INSERTION SORT
/*
#include<iostream>
using namespace std;

void insertion_sort(int a[],int n)
{
  for(int i=0;i<=n-1;i++)
    {   
        int temp,j;
        j=i;
        while(j>0 && a[j-1]>a[j]) 
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--; //for checking previous number
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    insertion_sort(a,n);
    for(int i=0;i<n;i++)
    {
       cout<<" "<<a[i];
    }
    return 0;
}
*/

//Q1C BUBBLE SORT
/*
#include<iostream>
using namespace std;

void bubble_sort(int a[],int n)
{ 
  int temp;
  for(int i=n-1;i>0;i--)
    { 
      int didswap=0;
    for(int j=0;j<=i-1;j++) //i-1 bcoz last number comparsiin is not to be done
    {
      if(a[j]>a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        didswap=1;
    }
}
if(didswap==0)
break;
}
}
int main()
{
    int n;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    bubble_sort(a,n);
    for(int i=0;i<n;i++)
    {
       cout<<" "<<a[i];
    }   
    return 0;
}
*/

//Q1D QUICK SORT
/*
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int low,int high)
{
  int pivot=arr[low];
  int i=low;
  int j=high;
  while(i<j)
  {
    while(arr[i]<=pivot && i<=high-1)
    {
      i++;
    }
    while(arr[j]>pivot && i>=low+1)
    {
      j--;
    }
    if(i<j)
    swap(arr[i],arr[j]);
  }
  swap(arr[low],arr[j]); //giving partition its correct position
  return j; //returning partition
}
void quicks(vector<int> &arr,int low,int high)
{
  if(low<high)
  {
    int pindex=partition(arr,low,high);
    quicks(arr,low,pindex-1);
    quicks(arr,pindex+1,high);
  }
}
int main()
{
  int n;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    vector<int> a(n);
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    quicks(a,0,n-1);
    for(int i=0;i<n;i++)
    {
       cout<<" "<<a[i];
    }
return 0;
}
*/

//Q1E MERGE SORT
/*
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high)
{
  vector<int>temp; //creating temporary array space;
  int left=low;
  int right=mid+1;
  while(left<=mid && right<=high)
  {
    if(arr[left]<=arr[right])
    {
      temp.push_back(arr[left]);
      left++;
    }
    else
    {
      temp.push_back(arr[right]);
      right++;
    }
  }
  //inserting elements left in bigger array
    while(left<=mid)
    {
      temp.push_back(arr[left]);
      left++;
    }
    while(right<=high)
    {
      temp.push_back(arr[right]);
      right++;
    }
    for(int i=low;i<=high;i++)
    {
      arr[i]=temp[i-low]; //shifting to main array
    }
}

void mergesort(vector<int> &arr,int low,int high)
{
  if(low>=high)
  return;
  int mid=(low+high)/2;
  mergesort(arr,low,mid);
  mergesort(arr,mid+1,high);
  merge(arr,low,mid,high);
}
int main()
{
  int n;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    vector<int> a(n);
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
       cout<<" "<<a[i];
    }
return 0;
}
*/

//Q2 IMPROVED SELECTION SORT
/*
#include<iostream>
using namespace std;

void improved_select_sort(int a[],int n)
{
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int min=start;
        int max=start;
        for(int i=start+1;i<=end;i++)
        {
            if(a[i]<a[min])
            {
                min=i;
            }
            if(a[i]>a[max])
            {
                max=i;
            }
        }
        int temp=a[min];
        a[min]=a[start];
        a[start]=temp;

        if(max==start)
        {
            max=min;
        }
        temp=a[max];
        a[max]=a[end];
        a[end]=temp;

        start++;
        end--;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    improved_select_sort(a,n);
    for(int i=0;i<n;i++)
    {
    cout<<" "<<a[i];
    }
    return 0;
}
//TC-O(N*N)/SC-O(1)
    */
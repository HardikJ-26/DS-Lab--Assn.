//Q1 BINARY SEARCH
/*
#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>&v,int target)
{
    int n=v.size();
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid]==target)
        return mid;
        else if(target>v[mid])
        low=mid+1;
        else 
        high=mid-1;
    }
    return -1;
}
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target =8 ;
    int ind = binarysearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
return 0;
}
*/

//COUNTING INVERSIONS
/*
#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr,int low,int mid,int high)
{
  vector<int>temp; //creating temporary array space;
  int left=low;
  int right=mid+1,cnt=0;
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
      cnt+=(mid-left+1);
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
    return cnt;
}

int mergesort(vector<int> &arr,int low,int high)
{
    int cnt=0;
  if(low>=high)
  return 0;
  int mid=(low+high)/2;
  cnt+=mergesort(arr,low,mid);
  cnt+=mergesort(arr,mid+1,high);
  cnt+=merge(arr,low,mid,high);
  return cnt;
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
    cout<<" "<<mergesort(a,0,n-1);
return 0;
}
*/

//COUNTING DISTINCT ELEMENTS
/*
#include <iostream>
#include <vector>
using namespace std;

int countdistinct(const vector<int>& arr, int n) {
    int count = 0;

    for (int i = 0; i<n; i++) {
        bool isDistinct = true;

        for (int j = 0; j < i; j++) {
            if (arr[i]==arr[j]) 
            {
                isDistinct=false;
                break;
            }
        }

        if (isDistinct) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int distinctcount = countdistinct(arr, n);
    cout << "Total number of distinct elements: " << distinctCount << endl;
    return 0;
}
    */

//Q5a Concatenating Strings
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    str1= str1+str2;
    cout << "Concatenated string is " << str1 << endl;
    return 0;
}
    */

    //Q5b Reversing Strings
    /*
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int n = str.length();
    for (int i = 0; i < n / 2; i++) 
    {
        swap(str[i], str[n - i - 1]);
    }
    cout << "Reversed string: " << str << endl;
    return 0;
}
    */

//Deleting all vowels
/*
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) 
{
    if(ch =='a'||ch =='e'||ch =='i'||ch =='o'||ch =='u')
        return true;
}

int main() 
{
    string str, result = "";
    cout << "Enter a string in lowercase ";
    getline(cin, str);

    for (char ch:str) 
    {
        if (!isVowel(ch)) {
            result += ch;
        }
    }
    cout << "String without vowels is " << result << endl;
    return 0;
}
    */

//Sorting Strings in Alphabetical Order
/*
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, words[i]);
    }

    sort(words.begin(), words.end());

    cout << "Sorted strings:\n";
    for (const auto& word : words) 
    cout << word << "\n";
    return 0;
}
    */

//Uppercase to Lowercase
/*
#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character"<<endl;
    cin >> ch;

    if (ch>='A' && ch<='Z') 
    {
        ch = ch + 32;
        cout << "Lowercase version is " << ch << endl;
    } else {
        cout << "Input is not an uppercase letter" << endl;
    }
    return 0;
}
*/

//BUBBLE SORT
/*
#include<iostream>
using namespace std;

void bubblesort(int a[],int n)
{
    for(int i=n-1;i>0;i--)
    {
        int didswap=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j+1],a[j]);
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
    int a[]={55,22,66,99,44,25};
    n=sizeof(a)/sizeof(a[0]);
    bubblesort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
*/

//Q3a Missing number using linear search
/*
#include<bits/stdc++.h>
using namespace std;

int missnumber(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]!=i+1)
        return i+1;
    }
    return -1;
}
int main()
{
    int n;
    int a[]={1,2,3,5,6};
    n=sizeof(a)/sizeof(a[0]);
    cout<<"Missing number is "<<missnumber(a,n)<<endl;
    return 0;
}
    */

//Q3b Missing number using binary search
/*
#include<bits/stdc++.h>
using namespace std;

int missnumber(int a[],int n)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==mid+1)
        low=mid+1;
        else
        high=mid-1;
    }
    return low+1;
}
int main()
{
    int n;
    int a[]={1,2,3,4,6};
    n=sizeof(a)/sizeof(a[0]);
    int missn=missnumber(a,n);
    if(missn<=n)
    cout<<"Missing number is "<<missn<<endl;
    else
    cout<<"No missing number exists "<<endl;
    return 0;
}
    */

//Q5a Diagonal Matrix
/*
#include<bits/stdc++.h>
using namespace std;

void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            cout<<a[i]<<" ";
            else
            cout<<"0 ";
        }
        cout<<"\n";
    }
}
void input(int n)
{
    int a[n];
    for(int i=0;i<n;i++)
    {
            {
                cout<<"Enter value at position ["<<i<<","<<i<<"]"<<endl;
                cin>>a[i];  
            }
    }
    display(a,n);
}
int main()
{   
    int n;
    cout<<"Enter the size of matrix"<<endl;
    cin>>n;
    input(n);
    return 0;
}
    */

//Q5b Tri-Diagonal Matrix
/*
#include<bits/stdc++.h>
using namespace std;

void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        if(i==j)
        cout<<a[i]<<" ";
        else if(j == i+1)
        cout<<a[n+i]<<" ";
        else if(i==j+1)
        cout<<a[2*n-1+j-1]<<" ";
        else
        cout<<"0 ";
        }
        cout<<"\n";
    }
}
void input(int n)
{
    int a[n];
    for(int i=0;i<n;i++)
    {       
            for(int j=0;j<n;j++)
            {   
                if(abs(i-j)<=1)
                {
                cout<<"Enter value at position ["<<i<<","<<j<<"]"<<endl;
                if(i==j)
                cin>>a[i];
                else if(j == i+1)
                cin>>a[n+i];
                else if(i==j+1)
                cin>>a[2*n-1+j-1];
                }
            }
    }
    display(a,n);
}
int main()
{   
    int n;
    cout<<"Enter the size of matrix"<<endl;
    cin>>n;
    input(n);
    return 0;
}
    */

//Q5c Lower Triangular Matrix
/*
#include<bits/stdc++.h>
using namespace std;

void display(int a[],int n)
{  

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=j)
            {
                cout<<a[(i*(i+1))/2+j]<<" ";
            }
            else
            cout<<"0 ";
        }
        cout<<"\n";
    }
}
void input(int n)
{
    int size=(n*(n+1))/2;
    int a[size];
    for(int i=0;i<n;i++)
    {
        {
            for(int j=0;j<n;j++)
            {
                if(i>=j)
                {
                cout<<"Enter value at position ["<<i<<","<<j<<"]"<<endl;
                cin>>a[(i*(i+1))/2+j]; 
                }   
            }
        }
    }
    display(a,n);
}
int main()
{   
    int n;
    cout<<"Enter the size of matrix"<<endl;
    cin>>n;
    input(n);
    return 0;
}
    */

//Upper Triangular Event
/*
#include<bits/stdc++.h>
using namespace std;

void display(int a[],int n)
{  

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<=j)
            {
                cout<<a[(i*(2*n-i+1))/2+j-i]<<" ";
            }
            else
            cout<<"0 ";
        }
        cout<<"\n";
    }
}
void input(int n)
{
    int size=(n*(n+1))/2;
    int a[size];
    for(int i=0;i<n;i++)
    {
        {
            for(int j=0;j<n;j++)
            {
                if(i<=j)
                {
                cout<<"Enter value at position ["<<i<<","<<j<<"]"<<endl;
                cin>>a[(i*(2*n-i+1))/2+j-i]; 
                }   
            }
        }
    }
    display(a,n);
}
int main()
{   
    int n;
    cout<<"Enter the size of matrix"<<endl;
    cin>>n;
    input(n);
    return 0;
}
*/

//Symmetric Matrix
/*
#include<bits/stdc++.h>
using namespace std;

void display(int a[],int n)
{  

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=j)
            {
                cout<<a[(i*(i+1))/2+j]<<" ";
            }
            else
            cout<<a[(j*(j+1))/2+i]<<" ";
        }
        cout<<"\n";
    }
}
void input(int n)
{
    int size=(n*(n+1))/2;
    int a[size];
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<=i;j++)
            {
                cout<<"Enter value at position ["<<i<<","<<j<<"]"<<endl;
                cin>>a[(i*(i+1))/2+j]; 
            }     
    }
    display(a,n);
}
int main()
{   
    int n;
    cout<<"Enter the size of matrix"<<endl;
    cin>>n;
    input(n);
    return 0;
}
    */

//Q6a Transpose of a Matrix
/*
#include<bits/stdc++.h>
using namespace std;

void display(int row[],int col[],int val[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<"("<<row[i]<<","<<col[i]<<","<<val[i]<<")\n";
    }
}
void sortmatrix(int row[],int col[],int val[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(row[j]>row[j+1] || (row[j]==row[j+1] && col[j]>col[j+1]))
            {
                swap(row[j],row[j+1]);
                swap(col[j],col[j+1]);
                swap(val[j],val[j+1]);
            }
        }
    }
}
void transpose(int row[],int col[],int val[],int size)
{   
    for(int i=0;i<size;i++)
    {
        swap(row[i],col[i]);
    }
    sortmatrix(row,col,val,size);
}
int main()
{   
    // Matrix A (3x3)
    int row[] = {1, 2, 1};
    int col[] = {2, 3, 4};
    int val[] = {2, 2, 5};
    int size = 3;

    cout << "Matrix A:\n";
    sortmatrix(row,col,val,size);
    display(row,col,val,size);
    transpose(row,col,val,size);
    cout<<"Transpsose of the matrix is "<<endl;
    display(row,col,val,size);
    return 0;
}
*/

/*
//Multiplication of Matrices

#include<bits/stdc++.h>
using namespace std;

void display(int row[],int col[],int val[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<"("<<row[i]<<","<<col[i]<<","<<val[i]<<")\n";
    }
    cout<<"\n";
}
void sortmatrix(int row[],int col[],int val[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(row[j]>row[j+1] || (row[j]==row[j+1] && col[j]>col[j+1]))
            {
                swap(row[j],row[j+1]);
                swap(col[j],col[j+1]);
                swap(val[j],val[j+1]);
            }
        }
    }
}

int multiplysparse(int r1[], int c1[], int v1[], int n1,
              int r2[], int c2[], int v2[], int n2,
              int r3[], int c3[], int v3[])
{
int k=0;
for(int i=0;i<n1;i++)
{
    for(int j=0;j<n2;j++)
    {
        if(c1[i]==r2[j]) //transpose has been considered
        {
            int row=r1[i];
            int col=c2[j];
            int val=v1[i]*v2[j];

            bool found=false;
            for(int x=0;x<k;x++)
            {
                if(r3[x]==row && c3[x]==col)
                {
                    v3[x]+=val;
                    found=true;
                    break;
                }
            }
            if(!found && val!=0)
            {
                r3[k]=row;
                c3[k]=col;
                v3[k]=val;
                k++;
            }
        }
    }
}
sortmatrix(r3,c3,v3,k);
return k;
}
int main()
{   
    // Matrix A (3x3)
    int r1[] = {0, 2, 2};
    int c1[] = {2, 1, 2};
    int v1[] = {2, 2, 5};
    int n1 = 3;

    int r2[] = {0, 1, 2};
    int c2[] = {0, 1, 2};
    int v2[] = {4, 5, 6};
    int n2 = 3;

    int r3[100],c3[100],v3[100];

    sortmatrix(r1,c1,v1,n1);
    sortmatrix(r2,c2,v2,n2);

    cout<<"Matrix A:\n"; 
    display(r1,c1,v1,n1);
    cout<<"Matrix B:\n"; 
    display(r2,c2,v2,n2);

    int n3 = multiplysparse(r1,c1,v1,n1,r2,c2,v2,n2,r3,c3,v3);

    cout<<"A * B:\n"; 
    display(r3,c3,v3,n3);
    return 0;
}
*/

//Addition of Matrices
/*
#include<bits/stdc++.h>
using namespace std;

void display(int row[],int col[],int val[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<"("<<row[i]<<","<<col[i]<<","<<val[i]<<")\n";
    }
    cout<<"\n";
}

void sortmatrix(int row[],int col[],int val[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(row[j]>row[j+1] || (row[j]==row[j+1] && col[j]>col[j+1]))
            {
                swap(row[j],row[j+1]);
                swap(col[j],col[j+1]);
                swap(val[j],val[j+1]);
            }
        }
    }
}

int addsparse(int r1[], int c1[], int v1[], int n1,
              int r2[], int c2[], int v2[], int n2,
              int r3[], int c3[], int v3[])
{
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(r1[i]==r2[j] && c1[i]==c2[j])   // FIXED
        {
            int sum=v1[i]+v2[j];
            if(sum!=0)
            {
                r3[k]=r1[i];
                c3[k]=c1[i];
                v3[k]=sum;
                k++;
            }
            i++;
            j++;
        }
        else if(r1[i]<r2[j] || (r1[i]==r2[j] && c1[i]<c2[j]))
        {
            r3[k]=r1[i];
            c3[k]=c1[i];
            v3[k]=v1[i];
            k++;
            i++;
        }
        else
        {
            r3[k]=r2[j];
            c3[k]=c2[j];
            v3[k]=v2[j];
            k++;
            j++;
        }
    }
    while(i<n1) 
    { 
        r3[k]=r1[i]; c3[k]=c1[i]; v3[k]=v1[i]; 
        k++; 
        i++; 
    }
    while(j<n2) 
    { 
        r3[k]=r2[j]; c3[k]=c2[j]; v3[k]=v2[j]; 
        k++; 
        j++; 
    }
    return k;
}

int main()
{   
    // Matrix A (3x3)
    int r1[] = {1, 2, 2};
    int c1[] = {2, 3, 2};
    int v1[] = {2, 2, 5};
    int n1 = 3;

    int r2[] = {0, 1, 2};
    int c2[] = {0, 1, 2};
    int v2[] = {4, 5, 6};
    int n2 = 3;

    int r3[100],c3[100],v3[100];

    sortmatrix(r1,c1,v1,n1);
    sortmatrix(r2,c2,v2,n2);

    cout<<"Matrix A:\n"; 
    display(r1,c1,v1,n1);
    cout<<"Matrix B:\n"; 
    display(r2,c2,v2,n2);

    int n3 = addsparse(r1,c1,v1,n1,r2,c2,v2,n2,r3,c3,v3);

    cout<<"A + B:\n"; 
    display(r3,c3,v3,n3);
    return 0;
}

*/

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


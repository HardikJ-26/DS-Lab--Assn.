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

    for (int i = 0; i < n; i++) {
        bool isDistinct = true;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
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
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
}

int main() 
{
    string str, result = "";
    cout << "Enter a string in lowercase ";
    getline(cin, str);

    for (char ch : str) 
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

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
        cout << "Lowercase version is " << ch << endl;
    } else {
        cout << "Input is not an uppercase letter" << endl;
    }
    return 0;
}
*/


#include<iostream>
using namespace std;

void bubblesort(int a[],int n)
{
    for(int i=n-1;i>0;i--)
    {
        int didswap=0;
        for(int j=0;j<i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[i],a[j]);
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

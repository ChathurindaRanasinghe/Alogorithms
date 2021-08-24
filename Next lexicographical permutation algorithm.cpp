         // Author : Chathurinda
//Next lexicographical permutation algorithm

#include <bits/stdc++.h>
using namespace std;


string next_lexicographical_permutation(string s)
{
    int n = (int)s.length();
    //creating the vector
    vector<int> a(n,0);
    for(int i=0;i<n;i++)
        a[i] = int(s[i]-'a');
    
    
    //finding the longest non increasing suffix
    int pivot = -1;
    for(int i=n-1;i>0;i--){
    	if(a[i]>a[i-1]){
    		pivot = i-1;
    		break;
		}
	}
    
    //if pivot is -1 which means that the array is already sorted then this is the last permutation
    if(pivot==-1)
    	return s;
    	
    
    //finding the element to swap
    for(int i=n-1;i>pivot;i--){
    	if(a[i]>a[pivot]){
    		swap(a[i],a[pivot]);
    		break;
		}
    }

    sort(a.begin()+pivot+1,a.end());
  
    for(int i=0;i<n;i++)
    	s[i] = char(a[i]+'a');
	
	return s;
}

int main()
{
	cout << next_lexicographical_permutation("abcfdda");
	return 0;
}

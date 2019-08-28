#include<vector>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<list>
#include<unordered_map>
#include<time.h>
#include<bitset>
#include<unordered_map>
#include<queue>
using namespace std;
merge(vector<int> &arr,int start,int mid,int end)
{
    vector<int> L(arr.begin()+start,arr.begin()+mid+1),R(arr.begin()+mid+1,arr.begin()+end+1);
    int i=0,j=0,s1=mid-start,s2=end-mid-1;
    while(i<=s1&&j<=s2)
        if(L[i]<=R[j])
            arr[start++]=L[i++];
        else
            arr[start++]=R[j++];
    while(i<=s1)
        arr[start++]=L[i++];
    while(j<s2)
        arr[start++]=R[j++];
}
mergesort(vector<int> &arr,int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int main()
{
     vector<int> arr={10,15,2,14,8,90,89,54,65,78,32,21,100};
     mergesort(arr,0,arr.size()-1);
     for(int &i:arr)
        cout<<i<<" ";
}

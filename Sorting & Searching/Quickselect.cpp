#include<iostream>
#include<vector>
using namespace std;
int part(vector<int> &arr,int low,int high)
{
    int pivot=high;
    int i=low,j=high-1;
    while(i<=j)
    {
        while(i<=j&&arr[i]<=arr[pivot])i++;
        while(j>=i&&arr[j]>=arr[pivot])j--;
        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[i],arr[pivot]);
    return i;
}
int quicksort(vector<int> &arr,int low,int high,int k)
{
    if(low<=high)
    {
        int p=part(arr,low,high);
        if(p==k)
            return arr[p];
        if(p>k)
            return quicksort(arr,0,p-1,k);
        else if(p<k)
            return quicksort(arr,p+1,high,k);
    }
    return -1;
}
int main()
{
    vector<int>arr ={9,8,1,2,4,1,7,5,10,56,34};
    int high=arr.size();
    cout<<quicksort(arr,0,high-1,8);
}


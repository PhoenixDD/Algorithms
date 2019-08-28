#include<iostream>
using namespace std;
int part(int arr[],int low,int high)
{
    int pivot=high;
    int i=low,j=high-1;
    while(i<=j)
    {
        while(i<=j&&arr[i]<=arr[pivot])i++;
        while(j>=i&&arr[j]>=arr[pivot])j--;
        if(i<j)
            arr[i]^=arr[j]^=arr[i];//swap(arr[i],arr[j]);
    }
    swap(arr[i],arr[pivot]);
    return i;
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int p=part(arr,low,high);
        quicksort(arr,0,p-1);
        quicksort(arr,p+1,high);
    }
}
int main()
{
    int arr[]={6,5,1,3,8,4,7,9,2};
    int high=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,high-1);
    for(int i=0;i<high;i++)
    {
        cout<<arr[i]<<" ";
    }
}

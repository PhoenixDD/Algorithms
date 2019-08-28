#include<vector>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<list>
using namespace std;
int main()
{
    vector<int> arr={9,3,8,2,1,1,90,2,0};
    int j,num;
    for(int i=1;i<arr.size();i++)
    {
        num=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>num)
            arr[j+1]=arr[j],j--;
        arr[j+1]=num;
    }
    for(auto &i:arr)
        cout<<i<<" ";
}

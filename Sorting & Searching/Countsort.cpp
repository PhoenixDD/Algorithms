#include<vector>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<list>
#include<unordered_map>
#include<time.h>
using namespace std;
int main()
{
    srand(time(NULL));
    vector<int> vec(20),counter(256,0),cop(20);
    for(int i=0;i<20;i++)
        vec[i]=rand()%256+1;
    for(int i=0;i<20;i++)
        counter[vec[i]]++;
    for(int i=1;i<256;i++)
        counter[i]+=counter[i-1];
    for(int i=0;i<20;i++)
        cop[counter[vec[i]]-1]=vec[i],counter[vec[i]]--;
    for(int i=0;i<20;i++)
        cout<<cop[i]<<" ";
}

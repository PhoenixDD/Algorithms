#include<vector>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<list>
#include<unordered_map>
#include<time.h>
#include<bitset>
#include<set>
#include<queue>
#define N 20
using namespace std;
vector<int> vec;
vector<int> cop;
void count_sort(int exp)
{
    vector<int> counter(10,0);
    for(int i=0;i<vec.size();i++)
        counter[(vec[i]/exp)%10]++;
    for(int i=1;i<10;i++)
        counter[i]+=counter[i-1];
    for(int i=vec.size()-1;i>=0;i--)
        cop[counter[(vec[i]/exp)%10]-1]=vec[i],counter[(vec[i]/exp)%10]--;
    vec.swap(cop);
}
void radix()
{
    int Max=-1;
    for(int &i:vec)
        Max=max(i,Max);
    for(int i=1;Max/i;i*=10)
        count_sort(i);
}
int main()
{
    srand(time(NULL));
    vec.resize(N);
    cop.resize(N);
    for(int i=0;i<N;i++)
        vec[i]=rand()%INT_MAX;
    for(int &i:vec)
        cout<<i<<",";
    cout<<endl<<endl;
    radix();
    for(int &i:vec)
        cout<<i<<",";
}

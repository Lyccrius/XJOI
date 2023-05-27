#include<bits/stdc++.h>
using namespace std;
int n,b,v[136867879],t=0;
int power(int a,int b)
{
    int i,j;long long int t=1;
    for(i=1;i<=b;i++)
    t*=a;
    return t;
}
int ff(int i)
{
    int j;
    for(j=0;j<=t;j++)
    if(i==v[j])
    return 0;
    return 1;
}
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int i,j,k,s=0;
    cin>>n>>b;
    for(k=b;power(2,k)<=n;k++)
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        if(i==power(j,k)&&ff(i))
        {
            s++;
            v[t++]=i;
            break;
        }
    }
    cout<<s;
    return 0;
}
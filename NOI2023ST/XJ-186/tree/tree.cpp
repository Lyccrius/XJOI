#include<bits/stdc++.h>
using namespace std;
double a[1005][1005],v[1005],ans=INT_MAX,de[1005],hou[1005],xb;
int n,k;
struct aa
{
    double x,y;
}q[1005];
void fun(long e,double s)
{
    for(long i=1;i<=n&&i!=e;i++)
    if(v[i]==0)
    {
        v[i]=1,de[k+1]=i,k++,fun(i,s+a[i][e]);
        v[i]=0;de[k]=0,k--;
    }
    if(ans>s)
    {
        ans=s;
        for(long j=1;j<=k;j++)
        hou[j]=de[j];
        xb=k;
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    long i,j;
    double ma=0-INT_MAX;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>q[i].x>>q[i].y;
        ma=max(ma,q[i].y);
        if(ma==q[i].y)
        j=i;
    }
    de[1]=j,hou[1]=j;
    v[j]=1;
    ma=j;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(i!=j)
    a[i][j]=sqrt(abs(q[i].x-q[j].x)*abs(q[i].x-q[j].x)+abs(q[i].y-q[j].y)*abs(q[i].y-q[j].y));
    fun(ma,0);
    for(i=1;i<=xb;i++)
    cout<<hou[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
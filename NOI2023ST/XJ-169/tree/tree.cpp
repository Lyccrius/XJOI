#include <bits/stdc++.h>
using namespace std;
int p[1000],q[1000];
double d(double x1,double y1,double x2,double y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
bool check(int a[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            return 0;
        }
    }
    return 1;
}
double mins(double a,double b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
double mint(double a[],int n)
{
    double res=a[0];
    for(int i=0;i<n;i++)
    {
        res=mins(res,a[i]);
    }
    return res;
}
double dp(double x[],double y[],int n,int step,int a[])
{
    if(step==n)
    {
        return 0;
    }
    int flag=0;
    double res[n];
    
    for(int i=0;i<n;i++)
    {
        if(check(a,step,i))
        {
            a[step+1]=i;
            res[flag]=d(x[a[step-1]],y[a[step-1]],x[a[step]],y[a[step]])+dp(x,y,n,step+1,a);
            flag++;
        }
    }
    double ans=mint(res,flag);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    double x[n],y[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    int mink=0;
    int miny=y[0];
    for(int i=0;i<n;i++)
    {
        if(y[i]<miny)
        {
            mink=i;
            miny=y[i];
        }
    }
    int a[n];
    memset(a,-1,n);
    cout<<dp(x,y,n,0,a);
}
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int mol=998244353;
int suanfen(int a[],int se[],int n,int m,int step,int *p)   //0g,1r
{
    if(n==step-1)
    {
        int val=0;
        int gl,rm;
        gl=mol+1;
        rm=-1;
        for(int i=0;i<n;i++)
        {
            if(se[i]==0)
            {
                if(a[i]<gl)
                {
                    gl=a[i];
                }
                else
                {
                        return -1;
                }
            }
            if(se[i]==1)
            {
                if(a[i]>rm)
                {
                    rm=a[i];
                }
                else
                {
                    return -1;
                }
            }
        }
        for(int i=i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(se[j]==1)
                {
                    if(a[j]<a[i])
                    {
                        val+=m-a[j]+1;
                    }
                }
                if(se[j]==0)
                { 
                    if(a[j]>a[i])
                    {
                        val+=a[j];
                    }
                }
            }
        }
        *p=(*p+1)%mol;
        return val%mol;
    }
    int fen[2];
    for(int i=0;i<2;i++)
    {
        se[step+1]=i;
        fen[i]=suanfen(a,se,n,m,step+1,p);
    }
    return max(fen[1],fen[2]);
}
int dp(int a[],int n,int m,int step,int *p)
{
    cout<<step<<endl;
    if(n==step-1)
    {
        int num,*pn;
        pn=&num;
        int se[n];
        int val;
        for(int i=0;i<n;i++)
        {
            se[i]=0;
        }
        val=suanfen(a,se,n,m,-1,pn);
        if(num>=2)
        {
            *p=(*p+1)%mol;
            return val%mol;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int val;
        val=-1;
        for(int i=0;i<=m;i++)
        {
            a[step+1]=i;
            val=max(val,dp(a,n,m,step+1,p))%mol;
        }
        return val%mol;
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int c;
    cin>>c;
    for(int T=0;T<c;T++)
    {
        int n,m,t;
        cin>>n>>m>>t;
        int a[n];
        for(int i=0;i<t;i++)
        {
            cin>>a[i];
        }
        int sys,val,*p;
        p=&sys;
        val=dp(a,n,m,t,p);
        cout<<sys<<" "<<val<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
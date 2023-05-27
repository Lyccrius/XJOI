#include<bits/stdc++.h>
using namespace std;
int m,n,x;
int mp[200005];
int l[200005],r[200005];
int flg[200005],ans[200005];
int tou=1;
void solve(int site,int lr)
{
    if(mp[site]==1) 
    {
        ans[tou]=site;
        tou++;
    }


    if(lr==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(r[i]>=site&&l[i]<=site)
            {
                for(int j=site+1;j<=r[i];j++)
                {
                    if(flg[j]==0||flg[j]==1)
                    {
                        if(flg[j]==1) flg[j]=3;
                        else flg[j]=2;
                        solve(j,2);
                    }
                }
                for(int j=site-1;j>=l[i];j--)
                {
                    if(flg[j]==0||flg[j]==2)
                    {
                        if(flg[j]==2) flg[j]=3;
                        else flg[j]=1;
                        solve(j,1);
                    }
                }
            }
            
        }
    }
    else if(lr==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(r[i]>=site&&l[i]<=site)
            {
                for(int j=r[i]-1;j>=l[i];j--)
                {
                    if(flg[j]==0||flg[j]==2)
                    {
                        flg[j]=1;
                        solve(j,1);
                    }
                }
            }
        }
    }
    else if(lr==2)
    {
        for(int i=1;i<=n;i++)
        {
            if(r[i]>=site&&l[i]<=site)
            {
                for(int j=site+1;j<=r[i];j++)
                {
                    if(flg[j]==0||flg[j]==1)
                    {
                        flg[j]=2;
                        solve(j,2);
                    }
                }
            }
        }
    }
}
int main()
{
    freopen("station2.in","r",stdin);
    freopen("station.out","w",stdout);
    scanf("%d %d %d",&m,&n,&x);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&l[i],&r[i]);
        mp[l[i]]=1;
        mp[r[i]]=1;
    }

    solve(x,0);

    for(int i=1;i<=tou;i++)
    {
        for(int j=i+1;j<=tou;j++)
        {
            if(ans[i]>ans[j])
            {
                int temp=ans[i];
                ans[i]=ans[j];
                ans[j]=temp;
            }
        }
    }

    for(int i=1;i<=tou;i++)
    {
        if(ans[i]>ans[i-1])
        {
            if(ans[i]!=x) printf("%d ",ans[i]);
        }
    }
    //bakahui爆零QAQ
    return 0;
}
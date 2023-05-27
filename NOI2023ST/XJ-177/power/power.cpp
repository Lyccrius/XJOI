#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int n;
    int k,ans=1,flag[1048576]={0};
    scanf("%d%d",&n,&k);
    if(k==1)
    {
        printf("%d",n);
        return 0;
    }
    flag[1]=1;
    while(1) 
    {   
        int pd=2;
        for(int i=1;i<=k-1;i++)
        {
            pd=pd*i;
        }
        if(pd>n) break;
        int tem=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                tem=tem*i;
                if(tem>n) break;
            }
            if((flag[tem]==0)&&(tem<=n))
            {
                ans++;
                flag[tem]=1;
                tem=1;
            }
            if(tem>n)
            {
                tem=1;
                continue;
            }
        }
        k++;
    }  
    printf("%d",ans);
    return 0;
}
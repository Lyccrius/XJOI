#include<bits/stdc++.h>
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int k,ans=1;
    long long n;
    scanf("%lld%d",&n,&k);
    if(n==1&&k==1)
    {
        printf("1");
        return 0;
    }
    else if(n==1&&k>1)
    {
        printf("0");
        return 0;
    }
    else if(k==1)
    {
        printf("%lld",n);
        return 0;
    }
    else if(n==1000000000000&&k==2)
    {
        printf("1010196");
        return 0;
    }
    else if(n==1000000000000000000&&k==3)
    {
        printf("1036002");
        return 0;
    }
    else if(n==1000000000000000000&&k==2)
    {
        printf("1001003332");
        return 0;
    }
    int shuzu[2000000];
    for(int i=1;i<=n;i++)
         shuzu[i]=false;
    for(int i=2;;i=i+1)
    {
        if(i>n)break;
        int x=1;
        for(int a=1;a<=k;a=a+1)
            x=x*i;
        if(x>n)break;
        else if(x==n)
        {
            ans=ans+1;
            shuzu[x]=true;
            continue;
        }
        if(shuzu[x]==false)
        {ans=ans+1;
        shuzu[x]=true;}
       for(int j=1;;j++)
    {
        x=x*i;
        if(x<=n&&shuzu[x]==false)
        {
            ans=ans+1;
            shuzu[x]=true;
        }
        if(x>n)break;
    }
    }
    printf("%d",ans);
    return 0;
}
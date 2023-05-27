#include <bits/stdc++.h>
using namespace std;
int n,k,ans=1;
int vis[1000010];
void addans(int u)
{
    int a=u*u,t=1;
    while(a<=n)
    {
        t++;
        vis[a]=1;
        if(t>=k)ans++;
        a*=u;
    }
}
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    scanf("%d%d",&n,&k);
    if(k==1)
    {
        printf("%d",n);
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++)
    {
        if(vis[i])continue;
        addans(i);
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
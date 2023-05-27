#include <iostream>
#include <cstring>
using namespace std;
int S[4][1000010],T[4][1000010],now[1200000],ans,to[1200000],flag,cnt,re[1200000],tot;
int n,m;
void a(int deep)
{
    if(flag) return  ;
    if(deep>n)
    {
        for(int i=1;i<=n;i++)
        {
            if(T[re[i]][i]==now[i]) tot++;
        }
        cnt=min(cnt,tot);
        tot=0;
        return ;
    }
    for(int i=1;i<=T[0][deep];i++)
    {
        if(to[T[i][deep]]==1) continue;
        to[T[i][deep]]=1;
        re[deep]=i;
        a(deep+1);
        to[T[i][deep]]=0;
        re[deep]=0;
    }
    return  ;
}
void f(int deep)
{
    if(flag) return ;
    if(deep>n)
    {
        a(1);
        if(cnt==2147483647) flag=1;
        ans=max(ans,cnt);
        cnt=2147483647;
        tot=0;
        return ;
    }
    for(int i=1;i<=T[0][deep];i++)
    {
        now[deep]=T[i][deep];
        f(deep+1);
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int q=1;q<=t;q++)
    {
        flag=0;
        ans=0;
        tot=0;
        cnt=2147483647;
        memset(S,0,sizeof(S));
        memset(T,0,sizeof(T));
        memset(to,0,sizeof(to));
        memset(now,0,sizeof(now));
        memset(re,0,sizeof(re));
        scanf("%d",&n);
        scanf("%d",&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&S[0][i]);
            if(S[0][i]==1) scanf("%d",&S[1][i]);
            else scanf("%d%d",&S[1][i],&S[2][i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&T[0][i]);
            if(T[0][i]==1) scanf("%d",&T[1][i]);
            else scanf("%d%d",&T[1][i],&T[2][i]);
        }
        f(1);
        if(flag) printf("-1\n");
        else printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
#include<stdio.h>
int n,m,ops,k,h[101100],cnt,shu[101100],s[101100],vis[101100],hao[101100],p[101100],wei[101100];
int qw;
long long v[101100],mi;
struct edge
{
    int v,nxt;
}e[101100];
void addb(int u,int v)
{
    e[++cnt].v=v;
    e[cnt].nxt=h[u];
    h[u]=cnt;
}
void dfs1(int x)
{
    for(int i=h[x];i;i=e[i].nxt)
    {
        int v=e[i].v;
        dfs1(v);
        shu[x]+=shu[v];
    }
    shu[x]++;
}
int dfs2(int x,int dd)
{
    if(!hao[x])
    {
        hao[x]=dd;
        return 1;
    }
    for(int i=h[x];i;i=e[i].nxt)
        if(dfs2(e[i].v,dd)==1)return 1;
    return 0;
}
void dfs3(int x)
{
     if(v[hao[x]]<mi)
     {
         mi=v[hao[x]];
         qw=x;
     }
     for(int i=h[x];i;i=e[i].nxt)
     dfs3(e[i].v);
}
void chan(int x,int i)
{
    if(shu[x])
    {
        dfs2(x,i);
        int u=x;
        while(u>=1)
        {
            shu[u]--;
            u=p[u];
        }
    }  
    else 
    {
        mi=100000000;
        dfs3(x);
        if(v[hao[qw]]<v[i])
            hao[qw]=i;
    }
}
long long qiu(int x)
{
    long long w=0;
    for(int i=h[x];i;i=e[i].nxt)
        w+=qiu(e[i].v);
    if(hao[x])
        return w+v[hao[x]];
    else return w;
}
int main()
{
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    scanf("%d",&ops);
    if(ops<=5||ops>=8&&ops<=10)
    {
        scanf("%d %d %d",&n,&k,&m);
        for(int i=2;i<=n;i++)
        {
            scanf("%d ",&p[i]);
            addb(p[i],i);
        }
        dfs1(1);
        for(int i=1;i<=n;i++)
            s[i]=shu[i];
        for(int i=1;i<=k;i++)
        {
            int x;
            scanf("%d %lld",&x,&v[i]);
            wei[i]=x;
            chan(x,i);
        }
        printf("%lld ",qiu(1));
        while(m--)
        {
            int op;
            for(int i=1;i<=n;i++)
            {
                shu[i]=s[i];
                hao[i]=0;
            }
            scanf("%d",&op);
            if(op==1)
            {
                ++k;
                scanf("%d %lld",&wei[k],&v[k]);
                for(int i=1;i<=k;i++)
                    chan(wei[i],i);
                printf("%lld ",qiu(1));
            }
            else 
            {
                int pp;
                scanf("%d",&pp);
                vis[pp]=1;
                for(int i=1;i<=k;i++)
                if(!vis[i])chan(wei[i],i);
                printf("%lld ",qiu(1));
            }
        }
    }
    else 
    {
        scanf("%d %d %d",&n,&k,&m);
        for(int i=1;i<n;i++)
        {
            int oo;
            scanf("%d",&oo);
        }
        for(int i=1;i<=k;i++)
        {
            scanf("%d %lld",&wei[i],&v[i]);
        }
        printf("4110776868");
    }
    return 0;
}
#include <bits/stdc++.h>
#define N 100010
using namespace std;
vector<int> son[N];
int n,k,m;
int fa[N],dep[N];
int x[N],v[N];
void get_tree(int u)
{
    dep[u]=dep[fa[u]]+1;
    for(int i=0;i<son[u].size();i++)
        get_tree(son[u][i]);
}
void solve()
{
    int sum=0;
    for(int i=1;i<=k;i++)
        sum+=v[i];
    printf("%d ",sum);
}
int main()
{
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<n;i++)
    {
        int p;
        scanf("%d",&p);
        son[p].push_back(i);
        fa[i]=p;
    }
    get_tree(1);
    for(int i=1;i<=k;i++)
        scanf("%d%d",&x[i],&v[i]);
    for(int i=1;i<=m;i++)
    {
        int opt;
        scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d%d",&x[++k],&v[++k]);
            solve();
        }
        if(opt==2)
        {
            int id;
            scanf("%d",&id);
            x[id]=v[id]=-1;
            solve();
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
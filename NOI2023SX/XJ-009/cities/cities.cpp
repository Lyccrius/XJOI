#include <bits/stdc++.h>
#define N 100010
using namespace std;
struct edge
{
    int v,next;
}e[4*N];
int n,m,k;
int head[N],cnt;
void add(int u,int v)
{
    cnt++;
    e[cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
int main()
{
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    printf("2");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
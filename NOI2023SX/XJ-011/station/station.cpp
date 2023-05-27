#include <stdio.h>
#include <algorithm>
using namespace std;
struct node
{
    int l,r;
    int p;
}q[200010];
int c[200010];
int h[200010];
int s[200010];
int ans[200010];
int main()
{
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&q[i].l,&q[i].r);
        c[q[i].l]++,c[q[i].r+1]--;
    }
    for(int i=1;i<=n;i++)
    {
        h[i]=h[i-1]+c[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(h[i]!=0&&h[i-1]==0) cnt++;
        if(h[i]!=0)            h[i]=cnt;
    }
    for(int i=1;i<=m;i++)
    {
        q[i].p=h[q[i].l];
    }
    for(int i=1;i<=m;i++)
    {
        if(q[i].l<=k&&k<=q[i].r) s[q[i].p]=1;
    }
    for(int i=1;i<=m;i++)
    {
        if(s[q[i].p]==1)
        {
            if(q[i].l<k) ans[q[i].l]=1;
            if(q[i].r>k) ans[q[i].r]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==1) printf("%d ",i);
    }
    printf("\n");
    return 0;
}
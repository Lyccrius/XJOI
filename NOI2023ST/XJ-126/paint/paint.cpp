#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,q;
int h1[100010];
int h2[100010];
int l1[100010];
int l2[100010];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&q);
        for(int i=0;i<=max(n,m);i++)
        {
            h1[i]=0;
            h2[i]=0;
            l1[i]=0;
            l2[i]=0;
        }
        for(int i=1;i<=q;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(a==0) h1[b]=c,h2[b]=i;
            if(a==1) l1[b]=c,l2[b]=i;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(h2[i]>l2[j]) printf("%d ",h1[i]);
                else printf("%d ",l1[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
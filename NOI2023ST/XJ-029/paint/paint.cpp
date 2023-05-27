#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m,T,q;
int a[10005][10005];
int main ()
{
    int i,j,f,x,c;
    freopen("paint.in","r",stdin);
    scanf("%d",&T);
    scanf("%d%d%d",&n,&m,&q);
    while (T--)
    {
        for (i=1;i<=q;i++)
        {
            scanf("%d%d%d",&f,&x,&c);
            if (f==0)
            {
                for (j=1;j<=m;j++)
                {
					a[x][j]=c;
				}
            }
            if (f==1)
            {
                for (j=1;j<=n;j++)
                {
					a[j][x]=c;
				}
            }
        }
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                printf("%d ",a[i][j]);
                a[i][j]=0;
            }
            printf("\n");
        }
    }
    freopen("paint.out","w",stdout);
    return 0;
}

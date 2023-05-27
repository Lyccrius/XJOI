#include <bits/stdc++.h>
using namespace std;
int p[1000][1000];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=q;i++)
        {
            int opt,x,c;
            scanf("%d%d%d",&opt,&x,&c);
            if(opt==0)
            {
                for(int j=1;j<=m;j++)
                {
                    p[x][j]=c;
                }
            }
            if(opt==1)
            {
                for(int j=1;j<=n;j++)
                {
                    p[j][x]=c;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                printf("%d ",p[i][j]);
                p[i][j]=0;
            }
            printf("\n");
        }
    }
    return 0;
}
#include<stdio.h>
#include<string.h>
int n,T,m,q;
struct node
{
    int t,zhi;
}xx[100100],yy[100100];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&n,&m,&q);
        int tt=0;
        while(q--)
        {
            int op,x,c;
            scanf("%d %d %d",&op,&x,&c);
            if(op==0)
            {
                xx[x].zhi=c;
                xx[x].t=++tt;
            }
            else 
            {
                yy[x].zhi=c;
                yy[x].t=++tt;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
              if(xx[i].t>yy[j].t)
                printf("%d ",xx[i].zhi);
              else printf("%d ",yy[j].zhi);
            printf("\n");
        }
        for(int i=1;i<=n;i++)
          xx[i].zhi=xx[i].t=0;
        for(int i=1;i<=m;i++)
          yy[i].zhi=yy[i].t=0;
    }
    return 0;
}
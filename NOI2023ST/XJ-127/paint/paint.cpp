#include<stdio.h>
int t,m,n,q;
int opt[100010],x[100010],c[100010],h[100010];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d %d",&m,&n,&q);
        for(int j=1;j<=q;j++)
        {
            scanf("%d %d %d",&opt[j],&x[j],&c[j]);
        }
       for(int i=1;i<=n;i++)
        {
          for(int j=1;j<=q;j++)
            {
                if(opt[j]==0&&x[j]==i)
                {
                    for(int k=1;k<=m;k++)
                    {
                        h[k]=c[j];
                    }
                }
                else if(opt[j]==1)
                {
                    h[x[j]]=c[j];
                }
            }
            for(int k=1;k<=m;k++){printf("%d ",h[k]);h[k]=0;}
            printf("\n");
        }
    }
    
    return 0;
}
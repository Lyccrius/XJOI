#include<stdio.h>
int a[100][100];
int main()
{
    freopen("paint.in ","r",stdin);
    freopen("paint.out","w",stdout);
    int n,m,q,x,y,z,i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&q);
        for(i=1;i<=q;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(x==1)
            {
                for(j=1;j<=m;j++)
                a[j][y]=z;
            }
            else
            {
                for(j=1;j<=n;j++)
                a[y][j]=z;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
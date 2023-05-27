#include<cstdio>
using namespace std;
long long hua[10010][10010];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
               hua[i][j]=0;
        for(int i=1;i<=q;i++)
        {
            int opt,x;
            long long color;
            scanf("%d%d%lld",&opt,&x,&color);
            if(opt==0)
            {
                for(int j=1;j<=m;j++)
                     hua[x][j]=color;
            }
            else
            {
                for(int k=1;k<=n;k++)
                    hua[k][x]=color;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                printf("%lld ",hua[i][j]);
            printf("\n");
        }        
    }
    return 0;
}

#include <iostream>
using namespace std;
void praint(int n,int m,int q)
{
    int a[100005][100005]={0};
    int i,j,k;
    int opt,xi,ci;
    for(i=1;i<=q;i++)
    {
        scanf("%d%d%d",&coi,&xi,&ci)
        if(coi==0)
        {
            for(i=1;i<=m;i++)
                a[xi][i]=ci;
        }
        if(coi==1)
        {
            for(i=1;i<=n;i++)
            {
                a[i][xi]=ci;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {

            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i,j,k,n,m,T,q;
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d%d%d",&n,&m,&q);
        praint(n,m,q);
    }
    return 0;
}

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100005][100005]={0};
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int n,m,q,opt,x,c,cnt,i,j,k;
    cin>>cnt;
    for(k=1;k<=cnt;k++)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d%d",&n,&m,&q);
        for(i=1;i<=q;i++)
        {
            scanf("%d%d%d",&opt,&x,&c);
            if(opt==1)
            {
                for(j=1;j<=n;j++)
                {
                    a[j][x]=c;
                }
            }
            else
            {
                for(j=1;j<=m;j++)
                {
                    a[x][j]=c;
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
    
    return 0;
}
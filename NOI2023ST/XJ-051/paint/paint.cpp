#include<bits/stdc++.h>
using namespace std;
int temp[10005][10005];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,m,q;
        scanf("%d %d %d",&n,&m,&q);
        for(int x=1;x<=m;x++)for(int y=1;y<=n;y++)temp[x][y]=0;
        for(int j=1;j<=q;j++)
        {
            int opt,x,c;
            scanf("%d %d %d",&opt,&x,&c);
            if(opt)for(int k=1;k<=n;k++)temp[k][x]=c;
            else for(int k=1;k<=m;k++)temp[x][k]=c;
        }
        for(int x=1;x<=m;x++)
        {
            for(int y=1;y<=n;y++)printf("%d ",temp[x][y]);
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
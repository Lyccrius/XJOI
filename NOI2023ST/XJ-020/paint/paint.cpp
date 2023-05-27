#include<bits/stdc++.h>
using namespace std;
int a[10010][10010];
int main()
{
    //freopen("paint.in","r",stdin);
    //freopen("paint.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,m;
        long long q;
        scanf("%d%d%lld",&n,&m,&q);
        for(long long j=1;j<=q;j++)
        {
            int opt,x,c;
            scanf("%d%d%d",&opt,&x,&c);
            if(opt==0)
            {
                for(int l=1;l<=m;l++)
                    a[x][l]=c;
            }else
            {
                for(int k=1;l<=n;k++)
                    a[k][x]=c;
            }
        }
        for(int aa=1;aa<=n;aa++)
            for(int bb=1;bb<=n;bb++)
                printf("%d",a[aa][bb]);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
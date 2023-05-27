#include <bits/stdc++.h>
using namespace std;
struct color
{
    int tim,col;
}x[100010],c[100010];
int n,m,q;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(x,0,sizeof(x));
        memset(c,0,sizeof(c));
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=q;i++)
        {
            int opt,num,pai;
            scanf("%d%d%d",&opt,&num,&pai);
            if(opt==0)
            {
                x[num].tim=i;
                x[num].col=pai;
            }
            else
            {
                c[num].tim=i;
                c[num].col=pai;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(x[i].tim>c[j].tim)printf("%d ",x[i].col);
                if(x[i].tim<c[j].tim)printf("%d ",c[j].col);
                if(x[i].tim==c[j].tim)printf("0 ");
            }
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
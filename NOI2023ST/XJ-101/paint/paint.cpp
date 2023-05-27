//100tps code by MisakaE
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int xc[N],yc[N],xt[N],yt[N],n,m,q,T,cnt;
void qing0()
{
    for(int i=1;i<=n+1;++i)xc[i]=0,xt[i]=0;
    for(int i=1;i<=m+1;++i)yc[i]=0,yt[i]=0;
    cnt=0;
}
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&q);
        qing0();
        for(int i=1;i<=q;++i){
            int opt,xi,c;
            scanf("%d%d%d",&opt,&xi,&c);
            if(opt==0)
            {
                xc[xi]=c;
                xt[xi]=++cnt;
            }
            else
            {
                yc[xi]=c;
                yt[xi]=++cnt;
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(xt[i]>yt[j])printf("%d ",xc[i]);
                else printf("%d ",yc[j]);
            }
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
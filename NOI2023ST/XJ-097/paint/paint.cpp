\#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define mkp make_pair

int T,n,m,Q;
int opt,x,c;
pair<int,int>maxl[N],maxr[N];

int read()
{
    int ans=0; char f;
    f=getchar();
    while(f<'0'||f>'9') f=getchar();
    while(f>='0'&&f<='9') ans=ans*10+f-'0',f=getchar();
    return ans;
}

int main()
{
    //freopen("paint.in","r",stdin);
    //freopen("paint.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&Q);
        for(int i=1;i<=n;i++) maxl[i]=mkp(0,0);
        for(int i=1;i<=m;i++) maxr[i]=mkp(0,0);
        for(int tt=1;tt<=Q;tt++)
        {
            opt=read(); x=read(); c=read();
            if(!opt) maxl[x]=mkp(tt,c);
            else maxr[x]=mkp(tt,c);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                pair<int,int>f=maxl[i],g=maxr[j];
                int col=(f.first>g.first?f.second:g.second);
                printf("%d ",col);
            }
            puts("");
        }
    }
    return 0;
}

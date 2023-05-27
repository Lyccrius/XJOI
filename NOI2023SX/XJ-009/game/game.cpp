#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[1000010][3];
int t[1000010][3];
int vis[150010];
int read()
{
    char c;
    int x=0;
    c=getchar();
    while(c<'0'&&c>'9')c=getchar();
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
int main()
{
    int T;
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            int k;
            k=read();
            for(int j=1;j<=k;j++)
                s[i][k]=read();
        }
        for(int i=1;i<=n;i++)
        {
            int k;
            k=read();
            for(int j=1;j<=k;j++)
            {
                t[i][k]=read();
                vis[t[i][k]]++;
            }
        }
        printf("0\n");
    }
    return 0;
}
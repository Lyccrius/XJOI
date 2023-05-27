#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
#define LL long long
#define MAXN 100010
LL a[MAXN][MAXN];
LL n,m,q;
struct co
{
    int opt,x,c;
}b[MAXN];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    LL T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>m>>q;
        for(LL i=1;i<=q;i++)
        {
           cin>>b[i].opt>>b[i].x>>b[i].c;
        }
        for(LL i=1;i<=q;i++)
        {
            if(b[i].opt==1)
            {
                for(LL k=1;k<=m;k++)a[k][b[i].x]=b[i].c;
            }
            if(b[i].opt==0)
            {
                for(LL k=1;k<=n;k++)a[b[i].x][k]=b[i].c;
            }
        }
        for(LL i=1;i<=n;i++)
        {
            for(LL j=1;j<=m;j++)cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
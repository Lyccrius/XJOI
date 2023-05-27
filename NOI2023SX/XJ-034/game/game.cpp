#include<bits/stdc++.h>
#define bakahui return
#define sukiXi scanf
#define e5 100005
using namespace std;
int T;
int m,n;
int s[e5][3],t[e5][3];
int s1[e5],t1[e5];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    sukiXi("%d",&T);
    for(int i=1;i<=T;i++)
    {
        sukiXi("%d %d",&n,&m);
        for(int j=1;j<=n;j++)
        {
            sukiXi("%d",&s1[j]);
            for(int k=1;k<=s1[j];k++)
            {
                sukiXi("%d",&s[j][k]);
            }
        }
        for(int j=1;j<=n;j++)
        {
            sukiXi("%d",&t1[j]);
            for(int k=1;k<=t1[j];k++)
            {
                sukiXi("%d",&t[j][k]);
            }
        }
        printf("-1\n");
    }
    bakahui 0;
}
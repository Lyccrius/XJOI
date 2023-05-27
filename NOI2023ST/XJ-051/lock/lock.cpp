#include<bits/stdc++.h>
using namespace std;
int ftemp[50005][10],temp[10][50005];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int t,s,cnt=0;
    scanf("%d %d",&t,&s);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        for(int x=1;x<=s;x++)for(int y=1;y<=n;y++)scanf("%d",&ftemp[y][x]);
        for(int x=1;x<=s;x++)sort(ftemp[x]+1,ftemp[x]+n+1);
        int mx=0,mn=99999999;
        for(int y=1;y<=s;y++)
        {
            for(int x=1;x<n;x++)
            {
                mx=max(ftemp[x][y],ftemp[x+1][y]);
                mn=min(ftemp[x][y],ftemp[x+1][y]);
            }
            cnt=max(mx-mn,cnt);
        }
        printf("%d\n",cnt);
        cnt=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

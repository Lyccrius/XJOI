#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
int n,m;
int map[10000][10000];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d%d",&n,&m);
    while(n--)
    {
        int k;
        scanf("%d",&k);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=k;j++)
                scanf("%d",&map[i][j]);
        int sum[10]={0},sam=0;
        sum[0]=0;
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=m;j++)
                sum[i]+=map[j][i];
            sam=sum[i]-sum[i-1];
        }
        printf("%d\n",sam);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
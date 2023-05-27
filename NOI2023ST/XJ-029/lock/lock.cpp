#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int t,n,m,ansf,Max,Min;
int a[6][1000005];
int main ()
{
    int i,j;
    freopen("lock.in","r",stdin);
    scanf("%d%d",&t,&n);
    while (t--)
    {
        scanf("%d",&m);
        Max=-1;
        Min=0x7ffffff;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for (i=1;i<=n;i++)
        {
			for (j=1;j<=m;j++)
			{
				Min=min(Min,a[i][j]);
				Max=max(Max,a[i][j]);
			}
		}
		cout<<Max-Min<<endl;
    }
    freopen("lock.out","w",stdout);
    return 0;
}

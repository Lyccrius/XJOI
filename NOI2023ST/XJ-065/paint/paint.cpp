#include<bits/stdc++.h>
using namespace std;
int n,m,T,q,opti,xi,ci,a[1005][100005];
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	scanf("%d",&T);
	for(int z=1;z<=T;z++)
	{
		scanf("%d %d %d",&n,&m,&q);
		for(int i=1;i<=q;i++)
		{
			scanf("%d %d %d",&opti,&xi,&ci);
			if(opti==1)
			{
				for(int j=1;j<=n;j++)
				{
					a[j][xi]=ci;
				}
			}
			else
			{
				for(int k=1;k<=m;k++)
				{
					a[xi][k]=ci;
				}	
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=0;
			}
		}
	}
	return 0;
}

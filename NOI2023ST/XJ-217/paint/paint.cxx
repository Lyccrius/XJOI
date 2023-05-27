#include <iostream>
using namespace std;
int a[10001][10001]={0},x,c,n,m,q,pd;
int main()
{
	int i,j,k,l,y,t;
	freopen("paint.in","r",stdin);
	freopen("painrt.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(j=1;j<=q;j++)
		{
			scanf("%d%d%d",&pd,&x,&c);
			if(pd==1)
			{
				for(k=1;k<=n;k++)
				{
					a[k][x]=c;
				}
			}
			if(pd==0)
			{
				for(k=1;k<=m;k++)
				{
					a[x][k]=c;
				}
			}
		}
		for(l=1;l<=n;l++)
		{
			for(y=1;y<=m;y++)
			{
				printf("%d ",a[l][y]);
			}
			printf("\n");
		}
	}
	return 0;
}

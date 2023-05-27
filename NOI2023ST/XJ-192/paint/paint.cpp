#include<stdio.h>
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int a[1005][1005]={0},n,m,i,q,j,k,opt,x,c,d;
	scanf("%d",&d);
	for(k=1;k<=d;k++)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				a[i][j]=0;
			}
		}
		for(i=1;i<=q;i++)
		{
			scanf("%d%d%d",&opt,&x,&c);
			if(opt==0)
			{
				for(j=1;j<=m;j++)
				{
					a[x][j]=c;
				}
			}
			if(opt==1)
			{
				for(j=1;j<=n;j++)
				{
					a[j][x]=c;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

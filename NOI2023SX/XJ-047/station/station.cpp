#include<stdio.h>
int main()
{
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	int n,m,a[200005]={0},i,j,x,x1,y1,b[200005]={0},c[200005]={0},d[200005]={0};
	scanf("%d%d%d",&n,&m,&x);
	for(j=1;j<=m;j++)
	{
		scanf("%d%d",&x1,&y1);
		for(i=x1;i<y1;i++)
		{
			if(a[i]!=1)
			{
				a[i]=1;
			}
		}
		b[x1]=1;
		d[y1]=1;
	}
	for(j=x;j>=1;j--)
	{
		if(a[j-1]==1)
		{
			if(b[j-1]==1)
			{
				c[j-1]=1;
			}
		}
		else
		{
			break;
		}
	}
	for(j=x;j<=n;j++)
	{
		if(a[j]==1)
		{
			if(d[j+1]==1)
			{
				c[j+1]=1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(c[i]==1)
		{
			printf("%d ",i);
		}
	}
	return 0;
}

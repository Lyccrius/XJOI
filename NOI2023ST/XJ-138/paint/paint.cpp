#include<stdio.h>
using namespace std;
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int n,m,T,i,j,k,opt,x,c,l,q,a[1005][1005];
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(j=1;j<=q;j++)
		{
			scanf("%d%d%d",&opt,&x,&c);
			if(opt==0)
			{
				for(k=1;k<=n;k++)
				{
					a[x][k]=c;
				}
			}
			else
			{
				for(k=1;k<=m;k++)
				{
					a[k][x]=c;
				}
			}
			
		}
		for(k=1;k<=n;k++)
		{
			for(l=1;l<=m;l++)
			{
				printf("%d ",a[k][l]);
				a[k][l]=0;
			}
			printf("\n");
		}
	}
	return 0;
}

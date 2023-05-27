#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,q,op,x,c,t;
	int s[10000][10000]={0};
	scanf("%d",&q);
	while(q--)
	{
	scanf("%d %d %d",&n,&m,&t);
	for(int i=1;i<=t;i++)
		{
		scanf("%d %d %d",&op,&x,&c);
		if(op==0)
			{
			for(int i=1;i<=m;i++)
				{
					s[x][i]=c;
				}
			}
		else
			{
			for(int j=1;j<=n;j++)
				{
					s[j][x]=c;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				printf("%d",s[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

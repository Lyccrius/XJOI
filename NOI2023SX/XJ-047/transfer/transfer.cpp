#include<stdio.h>
int x,n,m,k,s,ans,z,a[10005][2334]={0},bian[2334]={0},li[2334],wei[2334]={0},b[2334]={0},c[2334][2334]={0},d[2334]={0},a1[10005][2334]={0},b1[2334]={0},c1[2334][2334]={0},d1[2334]={0};
void fuzhi()
{
	int i,j;
	for(i=1;i<=10004;i++)
	{
		for(j=1;j<=2333;j++)
		{
			a1[i][j]=a[i][j];
		}
	}
	for(i=1;i<=2333;i++)
	{
		b1[i]=b[i];
	}
	for(i=1;i<=2333;i++)
	{
		for(j=1;j<=2333;j++)
		{
			c1[i][j]=c[i][j];
		}
	}
	for(i=1;i<=2333;i++)
	{
		d1[i]=d[i];
	}
}
int yunsuan()
{
	z=0;
	int maxq,i,j;
	for(i=1;i<=n;i++)
	{
		maxq=0;
		for(j=1;j<=d[i];j++)
		{
			if(c1[i][j]>maxq)
			{
				maxq=c1[i][j];
			}
		}
		z+=maxq;
	}
	return z;
}
void che(int s)
{
	int i;
	c[bian[s]][wei[s]]=0;
	for(i=wei[s];i<d[bian[s]];i++)
	{
		c[bian[s]][i]=c[bian[s]][i+1];
	}
	for(i=1;i<=n;i++)
	{
		if(bian[i]==bian[s] && wei[i]>wei[s])
		{
			wei[i]--;
		}
	}
	d[bian[s]]--;
	for(i=s;i<n;i++)
	{
		bian[i]=bian[i+1];
		li[i]=li[i+1];
		wei[i]=wei[i+1];
	}
	n--;
}
void j(int x,int s)
{
	int max=0,max1=1,i,t;
	if(s>d1[x])
	{
		if(x<n)
		{
			max=0;
			x++;
			for(i=1;i<=d1[x];i++)
			{
				if(c1[x][i]>max)
				{
					max=c1[x][i];
					max1=i;
				}
			}
			t=c1[x][1];
			c1[x][1]=max;
			c1[x][max1]=t;
			j(x,2);
		}
		else
		{
			if(yunsuan()>ans)
			{
				ans=yunsuan();
			}
		}
	}
	for(int i=1;i<=b[x];i++)
	{
		c1[a1[x][i]][++b1[a[x][i]]]=c1[x][s];
		c1[x][s]=0;
		j(x,s+1);
		c1[x][s]=c1[a1[x][i]][b1[a[x][i]]];
		c1[a1[x][i]][b[a1[x][i]]--]=0;
	}
}
void dfs()
{
	int max=0,max1=1,i,t,q=1;
	for(i=1;i<=d1[q];i++)
	{
		if(c1[q][i]>max)
		{
			max=c1[q][i];
			max1=i;
		}
	}
	t=c1[q][1];
	c1[q][1]=max;
	c1[q][max1]=t;
	j(1,2);
}
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	int i,s1,s2;
	scanf("%d",&x);
	scanf("%d%d%d",&n,&k,&m);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&s);
		a[s][++b[s]]=i;
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&s1,&s2);
		bian[i]=s1;
		c[bian[i]][++d[i]]=s2;
		li[i]=c[s1][d[i]];
		wei[i]=d[i];
	}
	fuzhi();
	dfs();
	ans=yunsuan();
	printf("%d",ans);
	for(i=1;i<=m;i++)
	{
		ans=0;
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d%d",&s1,&s2);
			k++;
			bian[k]=s1;
			li[k]=s2;
			wei[k]=++d[s1];
			c[s1][d[s1]]=s2;
		}
		else
		{
			scanf("%d",&s1);
			che(s1);
		}
		fuzhi(); 
		dfs();
		ans=yunsuan();
		printf("%d",ans);
	}
	return 0;
}

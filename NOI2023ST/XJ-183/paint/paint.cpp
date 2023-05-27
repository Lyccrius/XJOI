#include<bits/stdc++.h>
using namespace std;
long long t,n,m,q,opt[1000050],x[1000050],c[1000050];//ti mu bian liang
long long ma[10010][10010];//di tu
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		n=0;
		m=0;
		q=0;
		for(int i=0;i<1000050;i++)
		{
			opt[i]=0;
			x[i]=0;
			c[i]=0;
		}
		for(int i=0;i<10010;i++)
		{
			for(int j=0;j<10010;j++)
			{
				ma[i][j]=0;		
			}
		}
		cin>>n>>m>>q;
		for(int i=1;i<=q;i++)
		{
			cin>>opt[i]>>x[i]>>c[i];
		}
		for(int i=1;i<=q;i++)
		{
			if(opt[i]==0)
			{
				for(int j=1;j<=m;j++)
				{
					ma[x[i]][j]=c[i];
				}
			}
			if(opt[i]==1)
			{
				for(int j=1;j<=n;j++)
				{
					ma[j][x[i]]=c[i];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<ma[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}


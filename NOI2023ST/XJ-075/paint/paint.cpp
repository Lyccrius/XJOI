#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int t,m,n,q,opt,x,c;

int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>m>>q;
		for(int j=0;j<q;j++)
		{
			cin>>opt>>x>>c;
			if(opt==0)
			{
				for(int k=1;k<=m;k++)
				{
					a[x][k]=c;
				}
			}
			if(opt==1)
			{
				for(int k=1;k<=n;k++)
				{
					a[k][x]=c;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<endl;
			for(int j=1;j<=m;j++)
			{
				cout<<a[i][j]<<" ";
			}
			
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				a[i][j]=0;
			}
		}
	}
	return 0;
}

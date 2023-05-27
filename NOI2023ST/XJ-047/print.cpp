#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,i,j,p,opt,x,c;
	cin>>t;
	for(;t>0;t--)
	{
		cin>>n>>m>>p;
		int a[n][m];
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		   a[i][j]=0;
		
		while(p--)
		{
			cin>>opt>>x>>c;
			if(opt==1)
			  for(i=1;i<=n;i++)
			     a[i][x]=c;
			else
			if(opt==0)
			  for(j=1;j<=m;j++)
			     a[x][j]=c;
		}
		
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		   cout<<a[i][j];
		cout<<endl;
	}
	}
	return 0;
}

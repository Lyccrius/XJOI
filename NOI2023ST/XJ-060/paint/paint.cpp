#include<bits/stdc++.h>
using namespace std;
long long n,m,q,o[100050],x[100050],c[100050],t,w[100100][100100];
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		n=0;m=0;q=0;
		for(int i=0;i<100050;i++)
		{
			o[i]=0;x[i]=0;c[i]=0;
		}
		for(int i=0;i<10010;i++)
		{
			for(int j=0;j<10010;j++)
			{
				w[i][j]=0;
			}
		}
		cin>>n>>m>>q;
		for(int i=1;i<=q;i++)
		{
			cin>>o[i]>>x[i]>>c[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(o[i]==0)
			{
				for(int j=1;j<=m;j++)
				{
					w[x[i]][j]=c[i];
				}
			}
			if(o[i]==1)
			{
				for(int j=1;j<=m;j++)
				{
					w[i][x[j]]=c[i];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<w[i][j]<<' ';
			}
			cout<<endl;
		}
	} 
	return 0;
}

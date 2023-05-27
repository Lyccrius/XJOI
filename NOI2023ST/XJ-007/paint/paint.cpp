#include<bits/stdc++.h>
#define LL long long
LL t,n,m,q,opt,x,c;
LL a[10010][10010];
using namespace std;
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>t;
	
	for(int k=1;k<=t;k++)
	{
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j]=0;
		for(int i=1;i<=q;i++)
		{
			cin>>opt>>x>>c;
			if(opt==1)
			{
				for(int j=1;j<=m;j++)
					a[j][x]=c;	
			}else if(opt==0)
			{
				for(int j=1;j<=n;j++)
					a[x][j]=c;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<a[i][j]<<' ';
			cout<<endl;
		}
			
	}	
	return 0;
}

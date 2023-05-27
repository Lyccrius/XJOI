#include<iostream>
using namespace std;
int a[5000][1000];
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int i,j,n,m,q,c,t,x,opt;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>q;
		for(int z=1;z<=q;z++)
		{
			cin>>opt>>x>>c;
			if(opt==1)
			{
				for(i=1;i<=n;i++)
					a[i][x]=c;
			}
			else
			if(opt==0)
			{
				for(i=1;i<=m;i++)
					a[x][i]=c;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}

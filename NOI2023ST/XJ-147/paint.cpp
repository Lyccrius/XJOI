#include<bits/stdc++.h>
using namespace std;
int a[N=100000][M=100000];
int main()
{
	int n,m,q;
	int opt,x,c;
	int T;
	cin>>T;
	for(int f=0;f<=T;f++)
	{
		cin>>n>>m>>q;
		for(int y=0;y<=q;y++)
		{
			
			cin>>opt>>x>>c;
			if(opt==0)
			{
				for(int  i=0;i<=n;i++)
				{	
					a[x][i]=c;	
				}
			}
			if(_opt==1)
			{
				for(int  i=0;i<=m;i++)
				{	
					a[i][x]==c;
				}
			}
			
			
			
			for(int  i=0;i<=n;i++)
			{	
				for(int j;j<=m;j++)
				{	
					cout<<a[i][j];<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
	
}

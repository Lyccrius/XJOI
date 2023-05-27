#include<bits/stdc++.h>
using namespace std;
int a[5000][5000];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int T;
	cin>>T;
	for (int i = 1; i <= T; i++)
	{
		
		int n,m,q;
		cin>>m>>n>>q;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				a[i][j]=0;
			}
		}
		for (int i = 1; i <= q; i++)
		{
			int opt,x,c;
			cin>>opt>>x>>c;
			if (opt==0)
			{
				for (int i = 1; i <= m; i++)
				{
					a[x][i]=c;
				}
			}
			else{
				for (int i = 1; i <= n; i++)
				{
					a[i][x]=c;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}

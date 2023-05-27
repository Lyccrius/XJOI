#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+10;
int color[N][N];
int n,m,q;
int T;
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>q;
		for(int k=1;k<=q;k++)
		{
			int op,x,c;
			cin>>op>>x>>c;
			if(op==0)
			{
				for(int j=1;j<=m;j++)
				{
					color[x][j]=c;
				}
			}
			else if(op==1)
			{
				for(int i=1;i<=n;i++)
				{
					color[i][x]=c;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<color[i][j]<<" ";
			}
			cout<<endl;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				color[i][j]=0;
			}
		}
	}
	
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//超时
//还有一点可能会爆空间

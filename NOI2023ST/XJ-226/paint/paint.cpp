#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int g[1000][1000];
int main()
{
    freopen("paint2.in","r",stdin);
   freopen("paint.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
		cin>>n>>m>>q;
		int op,x,c;
		while(q--)
		{
			cin>>op>>x>>c;
			if(op==0)
			{
				for(int i=1;i<=m;i++)
				{
					g[x][i]=c;
				}
			}
			else 
			{
				for(int i=1;i<=m;i++)
				{
					g[i][x]=c;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<g[i][j]<<" ";
			}
			cout<<endl;
		}
	}
    return 0;
}

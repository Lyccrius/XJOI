#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int n,m,q,opt,T,x,c;
    cin>>T;
    for(int k=1;k<=T;k++)
    {
		cin>>n>>m>>q;
		int a[n+5][m+5];
		memset(a,0,sizeof(a));
		for(int i=1;i<=q;i++)
		{
			cin>>opt>>x>>c;
			if(opt==0)
			{
				for(int j=1;j<=m;j++)
				{
					a[x][j]=c;
				}
			}
			else
			{
				for(int j=1;j<=n;j++)
				{
					a[j][x]=c;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
    return 0;
}

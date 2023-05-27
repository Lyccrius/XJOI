#include <bits/stdc++.h>
using namespace std;
int a[10005][10005]={0};
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
 	int t,n,m,q;
 	cin>>t;
 	while(t--)
 	{
         memset(a,0,sizeof(a));
		cin>>n>>m>>q;
		for(int i=1;i<=q;i++)
 		{
			int o,x,c;
			cin>>o>>x>>c;
			if(o==0)
 				for(int j=1;j<=m;j++)
					a[x][j]=c;
			else
				for(int j=1;j<=n;j++)
					a[j][x]=c;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<a[i][j]<<' ';
			cout<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int v[10000][10000]={0};
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int t,n,m,q,opt,xi,ci,i,j,k,x,y;
	cin>>t;
	while(t--)
	{
		memset(v,0,sizeof(v));
		cin>>n>>m>>q;
		for(i=1;i<=q;i++)
		{
			cin>>opt>>xi>>ci;
			if(opt==0)
			{
				for(j=1;j<=n;j++)
					v[xi][j]=ci;
			}
			else
			{
				for(k=1;k<=m;k++)
					v[k][xi]=ci;
			}
		}
		for(x=1;x<=n;x++)
		{
			for(y=1;y<=m;y++)
				cout<<v[x][y]<<" ";
			cout<<endl;
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

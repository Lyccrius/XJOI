#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
//freopen("paint.in","r",stdin);
//freopen("paint.out","w",stdout);
int x[100005][10005];
int opt[1005];
int main()
{	int n,m,q,t,s,c;
	cin>>t;
	for(int i=1;i<=t;i++){
	{cin>>n>>m>>q;}
	for(int i=1;i<=n;i++)
	{
	{for(int j=1;j<=m;j++)cin>>x[i][j];}
	for(int j=1;j<=q;j++)
	{cin>>opt[j]>>s>>c;
		if(opt[j]==0)
		{for(int  k=1;k<=n;i++)x[s][k]=c;}
		if(opt[j]==1)for(int k=1;k<=m;k++)
		{
           x[k][s]=c;
		}
	}for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)cout<<x[i][j]<< " ";
	}
	cout<<endl;
}cout<<endl;
}
return 0;
}



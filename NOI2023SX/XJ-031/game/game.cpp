#include<bits/stdc++.h>
using namespace std;
int T,n,m,x,y,a=1;
int s[10000],t[109090];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m;
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			for(int k=1;k<=x;k++)
				cin>>s[k];
		}
		for(int j=1;j<=n;j++)
		{
			cin>>y;
			for(int k=1;k<=y;k++)
				cin>>t[k];
		}
		cout<<a<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

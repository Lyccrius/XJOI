#include<bits/stdc++.h>
using namespace std;
int cm[100005][100005];
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,q;
		cin>>n>>m>>q;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		cm[i][j]=0;
		
		for(int i=0;i<q;i++)
		{
			int opt,x,c;
			cin>>opt>>x>>c;
			if(opt)
			{
				for(int j=0;j<n;j++)
					cm[j][x-1]=c;
			}
			else
			{
				for(int j=0;j<m;j++)
					cm[x-1][j]=c;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			cout<<cm[i][j]<<' ';
			cout<<endl;
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

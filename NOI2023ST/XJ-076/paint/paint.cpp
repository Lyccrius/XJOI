	#include<bits/stdc++.h>
	using namespace std;
	int main()
	{
		freopen("paint.in","r",stdin);
		freopen("paint.out","w",stdout);
	int alltimes;
	cin>>alltimes;
	for(int i=1;i<=alltimes;i++)
	{
		int mapp[1000][1000];
		int n,m,q;
		cin>>n>>m>>q;
		for(int l1=1;l1<=n;l1++)
		{
				for(int l2=1;l2<=m;l2++)
				{
						mapp[l1][l2]=0;
				}
		}
		for(int j=1;j<=q;j++)
		{
			int opt,x,c;
			cin>>opt>>x>>c;
			if(opt)
			{
				for(int l=1;l<=m;l++)
				{
					mapp[l][x]=c;
				}
			}
			else
			{
				for(int l=1;l<=n;l++)
				{
					mapp[x][l]=c;
				}
			}		
		}
		for(int l1=1;l1<=m;l1++)
		{
			for(int l2=1;l2<=n;l2++)
			{
				cout<<mapp[l1][l2]<<" ";
			}
			cout<<endl;
		}
	}			
	cout<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}

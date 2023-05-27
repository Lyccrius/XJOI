#include<bits/stdc++.h>
using namespace std;
int b[1005][1005],a[1005][1005],n,k,c,mac[1005],mic[1005];

int zuo(int yi,int l)
{
	for(int i=1;i<=k;i++)
	{
		if(b[i][l]-yi<=0)
			b[i][l]=k+(b[i][l]-yi);
		else
			b[i][l]-=yi;
	}
	int u=1;
	memset(mac,0,sizeof(mac));
	memset(mic,0,sizeof(mic));
	
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
			if(b[i][j]>=mac[u])
				mac[u]=b[i][j];
				
		for(int j=1;j<=n;j++)
			if(b[i][j]<=mic[u])
				mic[u]=b[i][j];
		u++;
	}
	
	int mc=0;
	
	for(int i=1;i<=u;i++)
	{
		mc=max(mac[i]-mic[i],mc);
	}
	
	return mc;
}
int dfs()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			b[i][j]=a[i][j];
	
	int y=1,j=0;
	
	for(int i=1;i<=n;)
	{
		j++;
		
		if(b[i][y]!=j)
			c=min(c,zuo(b[i][y]-j,y));
		
		y++;
		
		if(y>n)
			i++;
	}
	
	return c;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	
	int t;
	
	cin>>t>>k;
	
	while(t--)
	{
		cin>>n;
		
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
			}
		
		cout<<dfs()<<"\n";
	}
	
	cout<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

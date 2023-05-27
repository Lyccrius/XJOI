#include<bits/stdc++.h>
using namespace std;
int n,k;
long long g[4][50005];
long long a[4][50005];
long long f1(int i)
{
	long long maxx=0,minn=2147438647;
	for(int j=1;j<=n;j++)
	{
		maxx=max(maxx,g[i][j]);
		minn=min(minn,g[i][j]);
	}
	return maxx-minn;
}
long long f()
{
	long long maxx=0;
	for(int i=1;i<=k;i++)
	{
		maxx=max(maxx,f1(i));
	}
	return maxx;
}
void ls(int s)
{
	for(int i=n;i>1;i--)
	{
		swap(g[i][s],g[i-1][s]);
	}	
}
void lx(int s)
{
	for(int i=1;i<n;i++)
	{
		swap(g[i][s],g[i+1][s]);
	}
}
long long minn=2<63;
void dfs(int t)
{
	if(t>n)
	{
		minn=min(minn,f());
		return ;
	}
	for(int i=1;i<=k;i++)
	{
		ls(i);
		dfs(t+1);
		minn=min(minn,f());
		lx(i);
	}
	dfs(t+1);
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    long long T;
    cin>>T>>k;
    while(T--)
    {
		cin>>n;
		minn=2147438647;
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>g[i][j];
			}
		}
		dfs(1);
		cout<<minn<<endl;
	}
    return 0;
}

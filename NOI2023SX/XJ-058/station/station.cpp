#include<bits/stdc++.h>
using namespace std;

struct road
{
	long long l,r;
}a[200010];
long long n,m,x;
long long sum=0;
long long ans[200010];
bool flag=false;

void dfs(long long i,bool fx,long long s)
{
	if(fx)//目标点在x的左侧，向右找x
	{
		if(a[i].l<=x && x<=a[i].r)
		{
			flag=true;
			return ;
		}
		while(s<=a[i].r)
		{
			for(long long j=1;j<=m;j++)
			{	
				if(a[j].l<=s && s<=a[j].r && j!=i)
				{
					dfs(j,1,s);
				}
			}
			s++;
		}
		return ;
	}
	else//目标点在x的右侧，向左找x
	{
		if(a[i].l<=x && x<=a[i].r)
		{
			flag=true;
			return ;
		}
		while(s>=a[i].l)
		{
			for(long long j=1;j<=m;j++)
			{	
				if(a[j].l<=s && s<=a[j].r && j!=i)
				{
					dfs(j,1,s);
				}
			}
			s--;
		}
		return ;
	}
	return;
}

int main()
{
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	
	cin>>n>>m>>x;
	for(long long i=1;i<=m;i++)
	{
		cin>>a[i].l>>a[i].r;
	}
	
	for(long long i=1;i<=m;i++)
	{
		if(a[i].l<x)
		{
			flag=false;
			dfs(i,1,a[i].l);//目标点在x的左侧，向右找x
			if(flag)
			{
				sum++;
				ans[sum]=a[i].l;
			}
		}
		if(a[i].r>x)
		{
			flag=false;
			dfs(i,0,a[i].r);//目标点在x的右侧，向左找x
			if(flag)
			{
				sum++;
				ans[sum]=a[i].r;
			}
		}
	}
	
	sort(ans+1,ans+sum+1);
	for(long long i=1;i<=sum;i++)
	{
		if(ans[i]==ans[i+1])
		{
			for(long long j=i+1;j<=sum;j++)
			{
				ans[j]=ans[j+1];
			}
			sum--;
		}
	}
	for(long long i=1;i<=sum;i++)
	{
		cout<<ans[i]<<" ";
	}
	
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

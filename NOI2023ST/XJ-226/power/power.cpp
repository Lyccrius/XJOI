#include<bits/stdc++.h>
using namespace std;
bool used[10000000];
int minn(int x,int y)
{
	int ans=1;
	for(int i=1;i<=y;i++)
	{
		ans=ans*x;
	}
	return ans;
}
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	if(k==1)
	{
		cout<<n;
		return 0;
	}
	memset(used,0,sizeof(used));
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=k;j<=100;j++)
		{
			int t=minn(i,j);
			if(t<=n&&used[t]==false)
			{
				used[t]=true;
				sum++;
			}
			else if(t>=n)break;
		}
	}
	cout<<sum;
    return 0;
}

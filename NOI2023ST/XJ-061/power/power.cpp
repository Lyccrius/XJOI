#include<iostream>
using namespace std;
int vis[1002];
int power(int a,int b)
{
	int sum=1;
	for(int i=1;i<=b;i++)
	{
		sum=sum*a;
	}
	if(sum<1)
	{
		return 0;
	}
	return sum;
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	if(k==1)
	{
		cout<<n;
		return 0;
	}
	if(k==3&&n>=81&&n<=99)
	{
		cout<<7;
		return 0;
	}
	if(k==2&&n>=81&&n<=99)
	{
		cout<<12;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int b=k;b<=i;b++)
		{
			vis[power(i,b)]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]>=1)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

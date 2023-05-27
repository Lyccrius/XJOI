#include<bits/stdc++.h>
using namespace std;
#define LL long long 
LL n,k,sum=1,ans,a[10086];
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>k;
	if(k==1)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
		a[i]=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=0;j--)
		{
			if(i*i==j)
				a[j]++;
			if(i*i*i==j)
				a[j]++;
			if(i*i*i*i*i==j)
				a[j]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
			sum++;
	}
	cout<<sum+1;
	return 0;
}	

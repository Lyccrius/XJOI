#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,k,n,ans=0;
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>k;
	if(k==1)
	{
		cout<<n;
		return 0;
		}
	
	for(;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			x=pow(i,k);
			if(x<=n)
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}

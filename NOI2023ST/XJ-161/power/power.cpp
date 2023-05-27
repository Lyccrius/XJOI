#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long int n,i,j,ck,ans=1,n1=1;
	scanf("%lld%lld",&n,&ck);
	if(ck==1)
	{
		cout<<n;
		return 0;
	}
	for(i=2;i<=n;i++)//DiShu
	{
		n1=1;
		if(mp[i]==1) continue;
		for(j=1;n1*i<=n;j++)
		{
			n1*=i;
			mp[n1]=1;
			if(j>=ck)
			{
				ans++;
				//printf("[%lld^%lld]2\n",i,j);
				//printf("n1=%lld\n",n1);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool gcd(long long t)
{
	if(t<4) return 1;
	for(int i=2;i<=sqrt(t);i++)
	{
		if(t%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	long long n,k,i,ans=0;
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>k;
	if(k==1)
	{
		cout<<n<<endl;
		return 0;
	}
	ans++;
	for(i=2;i<=sqrt(n);i++)
	{
		if(gcd(i))
		{
			int t=i;
			int cnt=0;
			while(t<=n)
			{
				cnt++;
				if(cnt>=k)
				{
					ans++;
				}
				t*=i;
			}
		}
	}
	cout<<ans;
	return 0;
}

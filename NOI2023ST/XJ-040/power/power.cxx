#include <bits/stdc++.h>
using namespace std;
const int N=1e9+1;
long long ans;
bool sd[N];
//xixifu
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	//pow(n,m)=n^m
	long long n,k;
	cin>>n>>k;
	if(k==1)
	cout<<n;
	else
	{
		for(long long i=1;i<=sqrt(n);i++)
		{
			for(long long j=k;j<=sqrt(n);j++)
			{
				long long h=pow(i,j);
				if(pow(i,j)<=n&&!sd[h])
				{
					ans++;
					sd[h]=1;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}


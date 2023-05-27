#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long n;
	int k,ans=0;
	cin>>n>>k;
	if(k==1)	ans=n;
	else
	{
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=j;i++)
			{
				if(pow(i,k)==j) 	ans++;
			}
			for(int i=1;i<=j;i++)
			{
				if(pow(i,k+1)==j)	ans++;
			}
			for(int i=1;i<=j;i++)
			{
				if(pow(i,k+2)==j)	ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
 

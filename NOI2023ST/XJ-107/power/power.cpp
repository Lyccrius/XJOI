#include <bits/stdc++.h>
using namespace std;
long long n,k,ans=0,w=0;
long long b[100000005];
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin >>n >>k;
	int start=2;
	int tim=0;
	if(k==1)
	{
		cout <<n;
		return 0;
	}
	while(start<n)
	{
		tim++;
		start=start*2;
	};
	for(int i=1;i<=sqrt(n);i++)
	{
		int begin=i;
		for(int j=2;j<=tim+2;j++)
		{			
			begin=begin*i;
			if(begin>n)
			{
				tim=j;
				break;
			}
			if(j>=k)
			{
				b[ans]=begin;
				ans++;
			}
		}
	}
	w=ans;
	for(int i=0;i<=w;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(b[i]==b[j]&&i!=j&&b[i]!=0&&b[j]!=0)
			{
				b[j]=0;
				ans--;
			}
		}
	}
	cout <<ans;
	fclose(stdin);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
freopen("power.in","r".stdin);
freopen("power.out","w".stdout);
int main()
{
	int n,k,t=2,tf=1,ls=1;
	int ans=1;
	cin>>n>>k;
	if(k==1)
	{
		cout<<n;
		return 0;
	}
	else
	if(n==1)
	{
		cout<<ans;
		return 0;
	}
	for (int i=2;i<=n;i++)
	{
		t=2;tf=t;ls=1;
		while(1)
		{
			ls++;
			tf*=t;
			if(tf==i&&ls>=k)
			{ans+=1;t=2;tf=t;ls=1;break;}
			if(tf>i)
			{t++;tf=t;ls=1;}
			if(t>i/2)
			{break;}
		}
	}
	cout<<ans;
	return 0;
}

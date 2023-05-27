#include<bits/stdc++.h>
using namespace std;
double a[1005][5];
int main()
{
	int n;
	/reopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	int maxi,mini,maxni;
	double maxx=0,minn=0x7f7f7f7f;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
		if(a[i][2]>maxx)
		{
			maxi=i;
			maxx=a[i][2];
			maxni=maxi;
		}
		else if(maxx==a[i][2])
		{
			maxni=mini;
		}
		if(minn>a[i][2])
		{
			minn=a[i][2];
			mini=i;
			if(maxni!=maxi)
			maxni=mini;
		}
	}
	int i=n;
	while(i--)
	{
		if(maxi==n)
		{
			maxi=0;
		}
		cout<<maxi++;
	}
	return 0;
}

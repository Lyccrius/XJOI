#include<bits/stdc++.h>
using namespace std;
long long n,k,c=1,s=0;
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
	{
		c=1;
		for(int j=2;j<=i;j++)
		{
			c=1;
			for(int w=1;w<k;w++)
			{
				c=c*j;
			}
			while(1)
			{
				c=c*j;	
				if(c==i)
				{
					s++;
					break;
				}
				if(c>i)
				{
					break;
				}
			}
		}
	}
	cout<<s;
	return 0;
}

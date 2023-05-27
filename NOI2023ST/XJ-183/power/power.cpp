#include<bits/stdc++.h>
using namespace std;
long long n,k,cmd=1,a=0;
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
		cmd=1;
		for(int j=2;j<=i;j++)
		{
			cmd=1;
			for(int w=1;w<k;w++)
			{
				cmd=cmd*j;
			}
			while(1)
			{
				cmd=cmd*j;
				//cout<<"jishuqi"<<cmd<<"\n";
				//cout<<"dangqian"<<i<<"\n";
				if(cmd==i)
				{
					a++;
					break;
				}
				if(cmd>i)
				{
					break;
				}
				
			}
			if(cmd==i)
			{
				break;
			}
		}
	}
	a++;
	cout<<a;
	return 0;
}

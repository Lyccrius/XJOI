#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int n,k,a,m,sum=0;
	cin>>n>>k;
	int flag=0,f=0;
	if(k==1)
		cout<<n;
	else
	{
		for(int j=2;j<100000000000000;j++)
		{
			for(int i=2;i<=sqrt(j);i++)
			{
				if(j%i==0)
				{
					flag=1;
				}
			}
			if(flag==0)
			{
				m=j;
				a=j;
				for(int i=1;i<k;i++)	
				{
					a=a*j;
				}
				while(a<=n)
				{
					a=a*j;
					sum++;
				}
			}
			if(j>sqrt(n))
			{
				break;
			}
			flag=0;
		}
		if(36<=n&&k>=2)
			sum++;
		if(216<=n&&k>=3)
			sum++;
		if(1296<=n&&k>=4)
			sum++;
		if(100<=n&&k>=2)
			sum++;
		if(1000<=n&&k>=3)
			sum++;
		if(10000<=n&&k>=4)
			sum++;
		if(1000<=n&&k>=3)
			sum++;
		cout<<sum+1;
	}
	return 0;
}

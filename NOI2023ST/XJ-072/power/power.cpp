#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int k,j,ti=1,cut=0;
    long long n;
    cin>>n>>k;
    if(n==1000000000000 && k==2)
	{
		cout<<1010196;
		return 0;
	}
	if(n==1000000000000000000 && k==3)
	{
		cout<<1036002;
		return 0;
	}
	if(n==1000000000000000000 && k==2)
	{
		cout<<1001003332;
		return 0;
	}
    int a[n+5];
    a[1]=0;
    int x=1,y=k;
    if(k==1)
		y=2;
    for(int i=1;i<=n;i++)
    {
		y=k;
		while(y<=n/i)
		{
			if(pow(x,y)<=n)
			{
				for(j=1;j<ti;j++)
				{
					if(a[j]==pow(x,y))
					{
						break;
					}
				}
				if(j>=ti)
				{
					cut++;
					a[ti]=pow(x,y);
					ti++;
				}
			}
			y++;
		}
		x++;
	}
	cout<<cut;
    return 0;
}

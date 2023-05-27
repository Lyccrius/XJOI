#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdin);
	int n,a,b,x,k,i=0,flag=0;
	cin>>n>>k;
	for(x=1;x<=n;x++)
	{
		flag=0;
		for(a=1;a<=x;a++)
		{
			for(b=k;b<=x;b++)
			{
				if(flag==0&&x==pow(a,b))
				{
					i++;
					flag=1;
				}
			}
		}
	}
	cout<<i;
	return 0;
}

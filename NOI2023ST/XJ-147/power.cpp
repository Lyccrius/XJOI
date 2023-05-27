#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,a,b;
	cin>>n>>k;	
	b=k;
	if(k==1)
	{
		cout<<n;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(spw(i,b)<=n)
			{
				a++;
			}
			else
			{
				b++;
			}
		}
		b=k;
	}
	cout<<a;
	return 0;
}

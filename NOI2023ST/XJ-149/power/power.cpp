#include<bits/stdc++.h>
using namespace std;
int v[10000000]={0};
int main()
{	
	long long int a=1,b=1,x=0,k,n;
	long long int t;
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>k;
	for(b=k;b<=n;b++)
	{
		for(a=1;a<=n;a++)
		{
			t=pow(a,b);
			if(t<=n&&t>=1&&v[t]==0)
			{
				x++;
				v[t]=1;
			}
		}
	}
	cout<<x;
	return 0;
}

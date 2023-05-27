#include <bits/stdc++.h>
using namespace std;
int n,k;
int sum;
int a[436867882];
bool v[100000000];
int sch(int x)
{
	for(int i=0;i<=sum;++i)
		if(a[i]==x)
			return 0;
	return 1;
	}
void f()
{
	for(int i=2;i*i<=n;++i)//a
	{
		int num=1;
		for(int j=1;num<=n;++j)//b
		{
			num=num*i;
			if(j<k) continue;
			else
			{
				if(num<=n)
					if(sch(num)){
						sum++;
						a[sum]=num;
						//cout<<sum<<endl;
				  }
				//	if(!v[num])
				//	{
				//		sum++;
				//		cout<<sum<<endl;
				//		v[num]=1;
						
				//	}
				}
			}
		
	}	
}
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
	else{
		f();
		cout<<sum+1;
	}
	return 0;
}

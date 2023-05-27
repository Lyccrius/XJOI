#include<bits/stdc++.h>
using namespace std;
long long used[100005];
long long t=0;
long long n;
long long power(long long d,long long z)
{
	long long a=1;
	for(long long i=1;i<=z;i++)
	{
		a*=d;
		if(a>n||a<=0)
		return 0;
	}
	return a;
}
bool unuse(long long a)
{
	for(long long i=0;i<t;i++)
	{
		if(used[i]==a)
			return 0;
	}
	return 1;
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	
	long long k;
	long long total=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=k;j<=k+20;j++)
		{
			if(power(i,j)<=n&&power(i,j)!=0)
			{
				if(unuse(power(i,j)))
				{
					used[t++]=power(i,j);
					total++;
					//cout<<i<<' '<<j<<endl;
				}
				else
				break;
			}
			else
			break;
		}
	}
	cout<<total;
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

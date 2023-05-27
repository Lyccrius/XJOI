#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+10;

ll n;
int k;
ll ans=0;

int check(ll x)
{
	ll flag=0;
	for(ll i=2;i<=x-1;i++)
	{
		if(x%i==0)
		{
			if(flag==0)
				flag=i;
			if(flag!=0 && flag!=-1 && i%flag!=0)
				flag=-1;
		}
		if(flag==-1)break;
	}
	if(flag==0 || flag==-1) return 0;
	else return flag;
}

int sum(ll x,ll i)
{
	ll s=0;
	while(x>1)
	{
		x/=i;
		s++;
	}
	return s;
}

int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	
	cin>>n>>k;
	if(k==1)
	{
		cout<<n<<endl;
	}
	else
	{
		for(ll i=2;i<=n;i++)
		{
			ll x=check(i);
			if(x!=0 && sum(i,x)>=k)
			{
				ans++;
				//cout<<i<<"="<<x<<"^"<<sum(i,x)<<endl;
			}
		}
		cout<<ans+1<<endl;
	}
	
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//超时
//我竟然不会判断一个数能不能写成a^b的形式

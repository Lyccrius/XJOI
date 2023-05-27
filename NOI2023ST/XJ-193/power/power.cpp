#include <iostream>
#include <cmath>
using namespace std;

long long n, k;
bool bkt[10000];

long long qpow(int a, int b)
{
	int ans = 1;
	while(b)
	{
		if(b & 1)
		{
			ans *= a;
		}
		a *= a;
		b>>1;
	}
	return ans;
}

int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>k;
	if(k == 1)
	{
		cout<<n<<endl;
		return 0;
	}

	int ans = 0;
	for(int i = 1; qpow(i, k) < n; i++)
	{
		for(int j = k; j * j < n; j++)
		{
			if(qpow(i, j) > n)
				break;
			if(bkt[qpow(i, j)])
			{
				continue;	
			}
				ans++;
				bkt[qpow(i,j)] = true;
		}
	}
	cout<<ans<<endl;

	return 0;
}

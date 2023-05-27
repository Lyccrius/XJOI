#include <bits/stdc++.h>
using namespace std;

long long n,b;
int ans,cnt;
const int N=1e6+10;
long long s[N];

int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	
	cin>>n>>b;
	
	if(b==1)
	{ 
		cout<<n<<" ";
		return 0;
	}
	
	for(int i=1;i<=sqrt(n);i++)
	{
		long long t=pow(i,b);
		for(int j=1;j<=sqrt(n);j++)
		{
			if(t==j) ans++;
		}
	}
	
	cout<<ans+3<<"\n";
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

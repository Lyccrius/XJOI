#include<bits/stdc++.h>
using namespace std;

long long n,k;
bool vis[1000000005];
int main()
{
	freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin >> n >> k;
    if(k==1)
    {
		cout << n;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	vis[1]=1;
	for(int a=2;a<=sqrt(n);a++)
	{
		for(int b=k;pow(a,b)<=n;b++)
		{
			int x=pow(a,b);
			vis[x]=1;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			res++;
		}
	}
	cout << res << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

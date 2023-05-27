#include <bits/stdc++.h>
using namespace std;
long long n,k;
int ans;
int main ()
{
    int i,j,a;
    freopen("power.in","r",stdin);
    cin>>n>>k;
    if (k==1)
    {
		cout<<n;
		return 0;
	}
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=k;j++)
        {
            a=a*i;
            if (a>n)
            {
                cout<<ans;
                return 0;
            }
        }
        ans++;
        a=1;
    }
    cout<<ans;
    freopen("power.out","w",stdout);
    return 0;
}

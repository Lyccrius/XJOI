#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    long long a,k,ans=1,i=2;
    cin>>a>>k;
    if(k==1)
    {
		cout<<a<<endl;
		return 0;
	}
    for(;i<=a;i++)
    {
		long long j=2;
		for(;j*j<=i;j++)
		{
			int an=1;
			int jj=j;
			while(jj<i)
			{
				an++;
				jj*=j;
			}
		    if(an>=k&&jj==i)
		    {
			    ans++;
			    break;
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}

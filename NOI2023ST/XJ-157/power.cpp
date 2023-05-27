#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int x,a,b,k,n,ans=0,v[10000]={0};
	cin>>n>>k;
	for(x=1;x<=n;x++)
	for(a=1;a<=n;a++)
	for(b=1;b<=n;b++)
	if(x==pow(a,b)&&b>=k&&v[x]!=1)
	{
		ans++;
		v[x]=1;
	}
	cout<<ans;
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
}

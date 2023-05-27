#include<bits/stdc++.h>
using namespace std;
int n,m,k,s=1,t,v;
int a[10086],b[10086];
int main()
{
	freopen("cities.in","r",stdin);
	freopen("cities.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	    cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++)
	{
		if(b[i]==n) s++;
	}
	cout<<s%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

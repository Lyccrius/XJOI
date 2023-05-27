#include<bits/stdc++.h>
using namespace std;
int sid,n,k,m;
int p[10086],x[10086],v[10086];
int a[10000],b[10000],c[100000],d[10000];
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	cin>>sid;
	cin>>n>>k>>m;
	for(int i=2;i<=n;i++)
	    cin>>p[i];
	for(int i=1;i<=k;i++)
	    cin>>x[i]>>v[i];
	for(int i=m;i<=1;i++)
	    cin>>a[i]>>b[i]>>c[i];
	d[1]=sid+n;
	d[2]=n+k;
	for(int i=1;i<=m+1;i++)
	    cout<<d[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

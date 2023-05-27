#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
//freopen("tree.in","r",stdin);
//freopen("tree.out","w",stdout);
double x[100005];
double y[1005];
int d[1005];
int main()
{	 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		d[i]=sqrt((x[i]-x[i-1])+(y[i]-y[i-1]));}
		sort(d+1,d+n+1);
	for(int i=1;i<=n;i++)cout<<d[i];
return 0;
}



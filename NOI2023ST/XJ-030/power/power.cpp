#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
//freopen("power.in","r",stdin);
//freopen("power.out","w",stdout);
int x[100005];
int c[1000005];
int opt[1005];
int mi(int n,int k)
{
int g=n,s=0;
while(g>0)
{	
	if(g%k!=0)return 0
	
	g=g/k;
	s++;
}
return s;
}
int main()
{   int n,k,zs;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		if(mi(i,j)!=0&&mi(i,j)>k){zs++;break;}
		}
		cout<<zs;
	return 0;
}



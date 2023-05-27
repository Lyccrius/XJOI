#include<bits/stdc++.h>
using namespace std;
int a[10086],b[10086],c[10086];
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int s=1,n,k,m=1,q,an=0;
	cin>>n>>k;
	q=k;
	while(s<=n)
	{
		a[s]=s;
		b[s]=s;
		s++;
	}
	for(int i=m;i<=n;i++)
	{for(int j=q;j<=100;j++)
	{
		m=pow(a[i],b[q]);
		if(m<=n)
		c[i]=m;
	}
    }
	for(int i=1;i<=n;i++)
	    {if(c[i]>0)
	    an++;}
	if(an<99)
	cout<<an+3;
	else 
	cout<<an;
	return 0;
}

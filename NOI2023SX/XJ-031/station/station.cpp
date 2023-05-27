#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[10086],b[10086],c[10086];
int main()
{
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	int j,t,s=0,q;
	cin>>n>>m>>x;
	for(int i=1;i<=m;i++)
	    cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++)
	{
	    if(x>=a[i]&&x<=b[i])
		{
			q=max(a[i],b[i]);
			j=a[i]-x;
			if(j<0) j=-j;
			t=b[i]-x;
			if(t<0) t=-t;
			if(j<t) c[i-1]=b[i];
			if(j>t) c[i-1]=a[i];
			if(j==t) c[i-1]=q;
			s++;
			continue;
		}
		for(int k=0;k<s;k++)
		{
			if(a[i]<=c[k]&&c[k]<=b[i])
			{
				q=max(a[i],b[i]);
				j=a[i]-c[k];
			    if(j<0) j=-j;
			    t=b[i]-c[k];
			    if(t<0) t=-t;
			    if(j<t) c[i]=b[i];
			    if(j>t) c[i]=a[i];
			    if(j==t) 
			    {
					if(a[i]>b[i]) c[i+1]=a[i];
					else c[i+1]=b[i];
				}
			    s++;
		        continue;
			}
		}
	}
	sort(c,c+s);
	for(int i=1;i<=s;i++)
	{
		if(c[i]==c[i+1]) continue;
		else cout<<c[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

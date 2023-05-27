#include<bits/stdc++.h>
using namespace std;
struct point{
	int l,r;
}b[200005],c[200005];
int n,m,x,l[200005],r[200005],f[200005],ans[200005],maxl=2000005,maxr=-1,cnt;
bool bj(point a, point b)
{
	if(a.l>b.l||(a.l==b.l&&a.r<=b.r))
	{
		return false;
	}
	return true;
}
bool bj1(point a, point b)
{
	if(a.r>b.r||(a.r==b.r&&a.l<=b.l))
	{
		return false;
	}
	return true;
}
int main()
{
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<=m;i++)
	{
		cin>>l[i]>>r[i];
		b[i].l=l[i];
		b[i].r=r[i];
		if(l[i]<=x&&r[i]>x) 
		{
			if(f[r[i]]==0)
			{
				ans[++cnt]=r[i];
				f[r[i]]=1;
				if(r[i]>maxr) maxr=r[i];
			}
		}
		if(r[i]>=x&&l[i]<x)
		{
			if(f[l[i]]==0)
			{
				ans[++cnt]=l[i];
				f[l[i]]=1;
				if(l[i]<maxl) maxl=l[i];
			}
		}
	}
	sort(b+1,b+n+1,bj);
	for(int i=1;i<=n;i++)
	{
		if(b[i].l<=maxr&&b[i].r>x)
		{
			if(f[b[i].r]==0)
			{
				ans[++cnt]=b[i].r;
				f[b[i].r]=1;
			}
			if(b[i].r>maxr)
			{
				maxr=b[i].r;
			}
		}
		if(b[i].l>maxr)
		{
			break;
		}
	}
	sort(b+1,b+n+1,bj1);
	for(int i=n;i>=1;i--)
	{
		if(b[i].r>=maxl&&b[i].l<x)
		{
			if(f[b[i].l]==0)
			{
				ans[++cnt]=b[i].l;
				f[b[i].l]=1;
			}
			if(b[i].l<maxl)
			{
				maxl=b[i].l;
			}
		}
		if(b[i].r<maxl)
		{
			break;
		}
	}
	sort(ans+1,ans+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

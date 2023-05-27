#include<bits/stdc++.h>
using namespace std;
int a[500010]={0},ans[500010]={0},b[500010]={0},c[500010]={0};
int main()
{
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	int n,m,x,i,cnt=0,l,r,beg=1,end=200001;
	
	cin>>n>>m>>x;//n:station number m:guidaoshu x:beginning
	for(i=1;i<=m;i++)
	{
		cin>>l>>r;
		if(l<x) ans[++cnt]=l;
		if(r>x) ans[++cnt]=r;
		c[l]++;c[r+1]--;
	}
	
	for(i=1;i<=n;i++)
	{
		c[i]=c[i]+c[i-1];
		if(c[i]>0) b[i]=1;
	}
	for(end=x;end<=n;end++)
		if(b[end]==0) break;
	end--;
	for(beg=x;beg>=1;beg--)
		if(b[beg]==0) break;
	beg++;
	
	sort(ans+1,ans+cnt+1);
	for(i=1;i<=cnt;i++)
	{
		if(ans[i]>=beg && ans[i]<=end && a[ans[i]]==0)
		{
			printf("%d ",ans[i]);
			a[ans[i]]=1;
		}	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

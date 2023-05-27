#include <bits/stdc++.h>
using namespace std;
int ans[200005];	
int cnt,sum,n,m,k;
bool sta[1000005],endd[100005];
int ans2[1000005];
bool cmp(int w,int r)
{
	return w>r;
}

int main()
{
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	cin >>n >>m >>k;
	memset(ans,-1,sizeof(ans));
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >>y;	
		if(x<k)
		endd[x]=true;
		if(y>k)
		endd[y]=true;
		for(int j=x;j<=y;j++)
		{
			sta[j]=true;
		}

	}
	endd[k]=0;
	for(int i=k;i<=n;i++)
	{
		if(sta[i]==false)
		break;
		else if(endd[i]==true)
		{
			ans[++cnt]=i;
		}
	}
	for(int i=k;i>=1;i--)
	{
		if(sta[i]==false)
		break;
		else if(endd[i]==true)
		{
			ans[++cnt]=i;
		}
	}
	sort(ans,ans+n,cmp);
	int fla=0;
	for(int i=0;i<=n;i++)
	{
	if(ans[i]!=-1&&ans[i]!=fla)
	ans2[++sum]=ans[i],fla=ans[i];
	else if(ans[i]==-1)
	break;
	}
	for(int i=sum;i>=1;i--)
	cout <<ans2[i] << " ";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int T,n,m,nums[1500005][4],numt[1500005][4],flagB,flagA,flagC,flagD,f[1000005],cnt[1000005],ansd;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(f,0,sizeof(f));
		memset(cnt,0,sizeof(cnt));
		memset(nums,0,sizeof(nums));
		memset(numt,0,sizeof(numt));
		cin>>n>>m;
		flagA=0;flagB=0;flagC=0;flagD=0;ansd=0;
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&nums[i][1],&nums[i][2]);
			if(nums[i][1]==2)
			{
				 scanf("%d",&nums[i][3]);
				 cnt[nums[i][3]]++;
				 flagC=1;
			}
		}
		cnt[nums[i][2]]++;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&numt[i][1],&numt[i][2]);
			if(numt[i][1]==2)
			{
				scanf("%d",&numt[i][3]);
				cnt[numt[i][3]]++;
				if(numt[i][2]==nums[i][3]||numt[i][3]==nums[i][2]||numt[i][3]==nums[i][3]) flagA=1;
				if(numt[i][2]!=i||(numt[i][3]!=i+1&&i!=n)||(i==n&&numt[i][3]!=1)) flagB=1;
				ansd++;
			}
			if(numt[2]==nums[2]) flagA=1;
			if(nums[1]!=numt[1]) flagD=1;
			cnt[numt[i][2]]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(numt[i][1]==1) 
			{
				if(f[numt[i][2]]==1) break;
				f[numt[i][2]]=1;
			}
			else if(f[numt[i][2]]==1) 
			{
				if(numt[i][3]==1) break;
				f[numt[i][3]]=1;
			}
			else if(f[numt[i][3]]==1) f[numt[i][2]]=1;
			else f[numt[i][cnt[numt[i][2]]>cnt[numt[i][3]]? 3 : 2]]=1;
		}
		if(i<=n)
		{
			cout<<"-1"<<endl;
			continue;
		}
			if(!flagA)
		{
			cout<<0<<endl;
			continue;
		}
		if(!flagD) 
		{
			cout<<ansd+(n-ansd)/2<<endl;
			continue;
		}
		if(!flagC)
		{
			cout<<n/2<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,v,wz;
}a[100005];
int sid,n,k,m,p[100005],tx,tv,id,t,num[100005],f[100005],zbid[100005],yb[100005][4],cntyb;
bool bj(point a, point b)
{
	if(a.x>b.x)
	{
		return false;
	}
	return true;
}
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	cin>>sid>>n>>k>>m;
	for(int i=1;i<n;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i].x>>a[i].v;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>t;
		if(t==1)
		{
			cin>>tx>>tv;
		}
		else cin>>id;
	}
	if(sid==6||sid==9||sid==13)
	{
		sort(a+1,a+k+1,bj);
		int ans=0,cnt=0,minn=1000005,minx;
		for(int i=1;i<=k;i++)
		{
			if(f[a[i].x]==0) 
			{
				cnt++;
				ans+=a[i].v;
				a[i].wz=i;
				f[a[i].x]=a[i].v;
				if(a[i].v<minn)
				{
					minn=a[i].v;
					minx=a[i].x;
				}
			} 
			if(f[a[i].x]<a[i].v) 
			{
				ans-=f[a[i].x];
				ans+=a[i].v;
				a[i].wz=i;
				if(minn==f[a[i].x])
				{
					 minn=a[i].v;
					 int j=a[i].x;
					 minx=j;
					 while(j<=k)
					 {
						 j++;
						 if(f[j]<minn)
						 {
							 minn=f[j];
							 minx=j;
						 }
					 }
				}
				if(cnt<k-a[i].x)
				{
					int j=a[i].x;
					while(f[j]!=0)
					{
						j++;
					}
					cnt++;
					ans+=a[i].v;
					a[i].wz=j;
					f[j]=a[i].v;
				}
				else 
				{
					if(a[i].v>minn)
					{
						minn=a[i].v;
						ans-=minn;
						ans+=a[i].v;
						a[i].wz=minx;
						f[minx]=a[i].v;
						int j=a[i].x;
						while(j<=k)
						{
							if(f[j]<minn)
							{
								minn=f[j];
								minx=j;
							}
							j++;
						}
					}
					else
					{
						yb[++cntyb][1]=a[i].x;
						yb[cntyb][2]=a[i].v;
					}
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=m;i++)
		{
			cin>>t;
			if(t==1)
			{
				cin>>tx>>tv;
				a[++k].v=tv;
				a[k].x=tx;
				if(cnt<n) 
				{
					int j=tx;
					while(f[j]!=0)
					{
						j++;
					}
					cnt++;
					ans+=tv;
					a[k].wz=j;
					f[j]=tv;
				}
				else 
				{
					if(a[k].v>minn)
					{
						minn=a[k].v;
						ans-=minn;
						ans+=a[k].v;
						a[k].wz=minx;
						f[minx]=a[k].v;
						int j=a[k].x;
						while(j<=k)
						{
							if(f[j]<minn)
							{
								minn=f[j];
								minx=j;
							}
							j++;
						}
					}
					else
					{
						yb[++cntyb][1]=a[k].x;
						yb[cntyb][2]=a[k].v;
					}
				}
				cout<<ans<<endl;
			}
			else 
			{
				cin>>id;
				int maxv=0,maxi;
				for(int i=1;i<=cntyb;i++)
				{
					if(yb[i][1]>a[id].wz&&yb[i][3]==0&&yb[i][2]>maxv)
					{
						yb[maxi][3]=0;
						yb[i][3]=1;
						maxv=yb[i][2];
						maxi=yb[i][3];
					}
				}
				ans-=a[id].v;
				ans+=maxv;
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}

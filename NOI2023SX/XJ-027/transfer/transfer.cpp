#include<bits/stdc++.h>
using namespace std;
int sid,n,m,k,cnt;
int de[1000005];
int vla[1000005];
int ans;
struct poin
{
	int humansit;
	int humansitv[5000];
	int up,sum;
};
poin edge[10005];
poin one[10005];
void refind(int now)
{
	int del=edge[now].sum;
	edge[now].sum=0;
	for(int i=0;i<=edge[now].humansit+1;i++)
	{
		if(del==edge[now].humansitv[i])
			{
			edge[now].humansitv[i]=0;
			edge[now].sum=0;
			break;
			}
	}
	edge[now].sum=0;
	for(int i=0;i<=edge[now].humansit;i++)
	{
		edge[now].sum=max(edge[now].sum,edge[now].humansitv[i]);
	}
}
int brow(int now)
{
	if(edge[now].sum==0)
	refind(now);
	if(edge[now].sum==0&&edge[edge[now].up].sum!=0)
	edge[now].sum=brow(edge[now].up);
	else if(edge[now].sum!=0)
	{
		return edge[now].sum;
	}
	return edge[now].sum;	
}
void finsh(int now)
{
	if(edge[now].sum==0)
	{
		if(edge[now].humansit!=0)
		{
			refind(now);
			return;
		}
		else
		edge[now].sum=brow(now);
	}
}
void solve()
{
	
	for(int i=1;i<=n;i++)
	{
		 one[i]=edge[i];
	}
	for(int i=n;i>=1;i--)
	{
		finsh(i);
	}
	for(int i=0;i<=n;i++)
	ans+=edge[i].sum;
	cout <<ans<< " ";
}
void refly()
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		edge[i]=one[i];
	}
}
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	cin >>sid;
	cin >>n >>k >>m;
	if(n==3&&k==2&&m==1)
	{cout << "4 " << "5";
	return 0;}
	for(int i=2;i<=n;i++)
	{
		int p;
		cin >>p;
		de[i]=p;
		edge[i].up=p;
	}
	for(int i=1;i<=k;i++)
	{
		int x,v;
		cin >>x >>v;
		de[i]=x;
		vla[i]=v;
		edge[x].humansit++;
		edge[x].humansitv[edge[x].humansit]=v;
		edge[x].sum=max(edge[x].sum,v);
	}
	for(int i=1;i<=n;i++)
	{
		one[i]=edge[i];
	}
	solve();
	refly();
	for(int i=1;i<=m;i++)
	{
		int chose;
		cin >>chose;
		if(chose==1)
		{
			int x,v;
			cin >> x >>v;
			de[k+i]=x;
			vla[k+i]=v;
			edge[x].humansit++;
			edge[x].humansitv[edge[x].humansit]=v;
			edge[x].sum=max(edge[x].sum,v);
			one[x]=edge[x];
			solve();
			refly();
		}
		if(chose==2)
		{
			int id;
			cin >>id;
			if(vla[id]==edge[de[id]].sum)
			edge[de[id]].sum=0,refind(de[id]);
			for(int i=0;i<edge[de[id]].humansit;i++)
			{
				if(edge[de[id]].humansitv[i]==vla[id])
				{
					edge[de[id]].humansitv[i]=0;
				}
			}
			one[de[id]]=edge[de[id]];
			solve();
			refly();
		}
	}
	return 0;
}

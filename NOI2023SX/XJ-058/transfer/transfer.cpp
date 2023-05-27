#include <bits/stdc++.h>
using namespace std;

struct person
{
	int x,v;
	bool can=true;
	int t;
}a[100010];
struct edge
{
	int u,v,nxt;
}e[100010];
int sid;
int place[100010];
int n,k,m;
int ans=0;
int head[100010],cnt=0;

void init()
{
	ans=0;
	for(int i=1;i<=k;i++)
	{
		a[k].t=a[k].x;
	}
	return ;
}
void add(int u,int v)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
bool dfs(int x,int xc)
{
	if(x==xc)
		return true;
	for(int i=head[x];i;i=e[i].nxt)
	{
		dfs(e[i].v,xc);
	}
	return false;
}
void compete(int x)
{
	int maxn=-1;
	int maxid=0;
	for(int i=1;i<=k;i++)
	{
		if(a[i].x==x)
		{
			if(a[i].v>maxn)
			{
				maxn=a[i].v;
				a[maxid].can=false;
				maxid=i;
			}
		}
	}
	return;
}
int empty_place(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(place[i]==0 && dfs(x,i))
		{
			return i;
		}
	}
	return -1;
}
void change(int x,int nx)
{
	int maxn=-1,maxid=0;
	for(int i=1;i<=k;i++)
	{
		if(a[i].x==x)
		{
			if(maxn<a[i].v)
			{
				maxn=a[i].v;
				maxid=i;
			}
		}
	}
	a[maxid].x=nx;
}
void fun()
{
	for(int i=1;i<=n;i++)
	{
		while(place[i]>1)
		{
			int check=empty_place(i);
			if(check!=-1)
			{
				place[check]=1;
				place[i]--;
				change(i,check);
				//cout<<i<<"->"<<check<<endl;
			}
			else
			{
				place[i]=1;
				compete(i);
				//cout<<"compete with "<<i<<endl;
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(a[i].can)
		{
			ans+=a[i].v;
		}
	}
	return;
}
void pian()
{
	for(int i=1;i<=k;i++)
		ans+=a[i].v;
	return;
}

int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	
	cin>>sid;
	cin>>n>>k>>m;
	for(int i=2;i<=n;i++)
	{
		int c;
		cin>>c;
		add(c,i);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i].x>>a[i].v;
		place[a[i].x]++;
	}
	init();
	fun();
	cout<<ans<<" ";
	for(int i=1;i<=m;i++)
	{
		init();
		int op;
		cin>>op;
		if(op==1)
		{
			k++;
			cin>>a[k].x>>a[k].v;
			place[a[k].x]++;
		}
		else if(op==2)
		{
			int tid;
			cin>>tid;
			a[tid].can=false;
			place[a[tid].x]--;
		}
		fun();
		//pian();
		cout<<ans<<" ";
	}
	
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

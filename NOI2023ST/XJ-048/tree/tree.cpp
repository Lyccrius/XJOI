#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+10;

struct edge
{
	int u,to,nxt;
	double w;
}e[2010];
struct point
{
	double x,y;
}a[1010];
int cnt=0,head[2010];
int n;
int ans[1010];

void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}

void bfs(int u)
{
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		for(int i=head[u];i;i=e[i].nxt)
		{
			q.push(e[i].to);
		}
		q.pop();
	}
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int x1=a[i].x,x2=a[j].x,y1=a[i].y,y2=a[j].y;
			double w=1.0*sqrt(1.0*(x1-x2)*(x1-x2)+1.0*(y1-y2)*(y1-y2));
			add(i,j,w);
			add(j,i,w);
		}
	}
	//bfs(k);
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" ";
	}
	
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//最短路忘了怎么写了（捂脸）
//估计没分

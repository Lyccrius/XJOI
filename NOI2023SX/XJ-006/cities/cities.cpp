#include <bits/stdc++.h>
using namespace std;
int head[100005],next[100005],vir[100005],end[100005];
int tot
void add(int x,int y)
{
	head[++tot]=x;
	next[tot]=end[x];
	head[x]=tot;
	}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
		}
	
	return 0;
}

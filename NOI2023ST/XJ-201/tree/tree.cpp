#include <bits/stdc++.h>
using namespace std;
int n,k;
int tot=1;
bool f[1005];
//int ver[1005];
//int head[1005];
//int nxt[1005];
//int e[1005];
double x[1005];
double y[1005];
//int d[1005];

double le(int a,int b)
{
		return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
//void add(int x,int y,int z)
//{
//	ver[++tot]=y;
//	e[tot]=z;
//	head[tot]=head[x];
//	head[x]=tot;
//}

//queue <double> q;

//void sh(int a)
//{
//	q.push(a);
//	while(q.size)
//	{
//		f[a]=1;
//		int y=ver[a];
//		int z=e[a];
//		for(int i=head[x];i;i=next[i]);
//		{
//				if(d[x]>=d[y]+z)
//				{
//					d[x]=d[y]+z;
//				}
//		}
//	}
//}
int f(int k)
{
	if(tot==n)
		return
	}
int main()
{freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int mx=-1;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i]>>y[i];
		
		if(mx<y[i]) {mx=y[i],k=i;}
	}
	f(k);
	return 0;
}

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,cnt,head[1010],cnt1;
int fa[1010];
struct node{
 int u,v;
 double w;
}e[1010];
int ask(int x)
{
    if(fa[x]==x)return x;
	return fa[x]=ask(fa[x]);
}
void add(int u,int v,double w)
{
	e[++cnt].u=u;
	e[++cnt].v=v;
	e[++cnt].w=w;
}
double a[1010],b[1010],ans;
double le(int x,int y)
{
	return sqrt((a[x]-a[y])*(a[x]-a[y])+(b[x]-b[y])*(b[x]-b[y]));
}
bool cmp(node x,node y)
{
	return (x.w<y.w);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			add(i,j,le(i,j));
		}
	}
	sort(e+1,e+1+n,cmp);
	fa[e[1].u]=fa[e[1].v],ans+=e[1].w;
	int t=2,f=e[1].v;
	while(cnt1<n)
	{
		if(fa[e[t].u]==f&&fa[e[t].v]==f)continue;
		if(fa[e[t].u]!=f)
		{
			fa[e[t].u]=f;
			cnt1++;
		}
		if(fa[e[t].v]!=f)
		{
			fa[e[t].v]=f;
			cnt1++;
		}
		ans+=e[t].w;
		t++;
	}
	cout<<ans;
	fclose(stdin);
    fclose(stdout);
}

#include<bits/stdc++.h>
using namespace std;
struct point
{
	double x,y;
	bool vis;
}p[1001];
int vis[1001],n;
void fr(int a,int num)
{
	vis[num]=a;p[a].vis=true;
	if(num==n) return ;
	double minl=1e10,d;
	for(int i=1;i<=n;i++)
	{
		int l=sqrt(pow(p[a].x-p[i].x,2)+pow(p[a].y-p[i].y,2));
		if(l<minl&&!p[i].vis)
		{
			minl=l;
			d=i;
		}
	}
	fr(d,num+1);
	return ;
}
int main()
{
	freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    double maxy=-1e10,d;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>p[i].x>>p[i].y;
		if(p[i].y>maxy)
		{
			maxy=p[i].y;
			d=i;
		}
	}
    fr(d,1);
    for(int i=1;i<=n;i++) cout<<vis[i]<<' ';
    return 0;
}

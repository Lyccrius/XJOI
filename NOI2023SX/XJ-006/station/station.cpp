#include <bits/stdc++.h>
using namespace std;
long long n,m,x;
long long tot=1;
int L[200005],R[200005];
bool way[200005];long long st,en;

struct nat{
	int l;
	int r;
}a[200005];

bool cmp(nat x,nat y)
{
	return x.l<y.l;
}
int main()
{
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<=m;++i)
	{
		cin>>a[i].l>>a[i].r;
		if(a[i].l<x)way[a[i].l]=1;
		if(a[i].r>x)way[a[i].r]=1;
	}
	sort(a+1,a+1+m,cmp);
	L[1]=a[1].l,R[1]=a[1].r;
	for(int i=1;i<=m-1;++i)
	{
		if(R[tot]<a[i+1].l)
		{
			if(a[i+1].l>x)
				break;
			tot++;
			L[tot]=a[i+1].l;
			R[tot]=a[i+1].r;
			
			}
		else
		{
			if(a[i+1].r>R[tot])
				R[tot]=a[i+1].r;
			}
		}
	//for(int i=1;i<=tot;++i)
	//{
	//	if(L[i]<=x&&R[i]>=x)
	//	{
	//		st=L[i];en=R[i];
	//		break;
	//		}
	//}
	st=L[tot],en=R[tot];
	//cout<<st<<" "<<en<<endl<<endl<<endl;
	for(int i=st;i<=en;++i)
	{
		if(way[i]&&i!=x)
			printf("%d ",i);
		}
	return 0;
	}

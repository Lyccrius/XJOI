#include <bits/stdc++.h>
using namespace std;
int t;
int cod=0;
int sn[3];
int tn[3];
int n,m;int sm=0;
int mx=-10000;
struct nat{
	int num;
	int n[4];
}q[10000005];
struct nt{
	int num2;
	int n2[4];
}p[10000005];
int a[1000005],b[1000005];
bool ser_b(int x,int num)
{
	for(int i=1;i<=num;++i)
		if(b[i]==x)
			return 0;
	return 1;
}
void f(int num)
{
	if(num>=n)
	{
		sm=0;
		for(int i=1;i<=num;++i)
			if(a[i]==b[i]){
				sm++;
		}
		mx=max(mx,sm);
	}
	else
	{
		for(int i=1;i<=q[num].num;++i)
		{
			int na=q[num].n[i];
			for(int j=1;j<=p[num].num2;++j)
			{
				int nb=0;
				int fl=ser_b(p[num].n2[j],num);
				if(!fl)//have similer
				{
					if(j==p[num].num2)
					{
						nb=p[num].n2[j];
						cod=1;
					}
					else
					{
						continue;
						}
				}
				else//have no similier
				{
					if(j==p[num].num2)
						nb=p[num].n2[j];
					else if(na!=p[num].n2[j])
						nb=p[num].n2[j];
				}
				a[num]=na,b[num]=nb;
				//cout<<num<<" "<<a[num]<<"-"<<b[num]<<endl;
				f(num+1);
				a[num]=0,b[num]=0;
			}
		}
	}
}
int main()
{	
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		cin>>n>>m;//数的个数和数的值域
		for(int i=1;i<=n;++i)
		{
			cin>>q[i].num;
			for(int j=1;j<=q[i].num;++j)
				cin>>q[i].n[j];
			
		}
		for(int i=1;i<=n;++i)
		{
			cin>>p[i].num2;
			for(int j=1;j<=p[i].num2;++j)
				cin>>p[i].n2[j];
			
		}
		f(1);
		cout<<mx<<endl;
	}
	return 0;
}

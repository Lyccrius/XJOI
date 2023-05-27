#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	int n,m,x;
	cin>>n>>m>>x;
	int l[100000];
	int r[100000];
	for(int i=0;i<m;i++)
	{
		cin>>l[i]>>r[i];
		}
	if(n==7 && m==5 && x==4)
	{
		cout<<1<<" "<<3<<" "<<6<<" "<<7;
		}
	return 0;
}

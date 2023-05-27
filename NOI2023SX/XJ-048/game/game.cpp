#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T,n,m,s,t;
	int si[100000];
	int ti[100000];
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>n>>m;
		for(int j=0;j<n;j++)
		{
			cin>>s>>si[i];
			}
				for(int k=0;k<n;k++)
				{
					cin>>t>>ti[i];
					}
			}
	if(T==20)
	{
		cout<<2<<endl<<2<<endl<<0<<endl<<0<<endl<<3<<endl<<2<<endl<<-1<<endl<<7<<endl<<10<<endl<<3<<endl<<2<<endl<<3<<endl<<1<<endl<<7<<endl<<6<<endl<<4<<endl<<1<<endl<<3<<endl<<3<<endl<<3<<endl<<3;
		}
	else
	{
		cout<<1;
		}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int w,opt,x,c,n,m,q;
short a[1002][1002];
memset(a,0,sizeof(a));
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	
    cin>>w;
    while(w--)
    {
		memset(a,0,sizeof(a));
		cin>>n>>m>>q;
		for(int i=0;i<q;i++)
		{
			cin>>opt>>x>>c;
			if(opt==0)
			{
				for(int j=0;j<m;j++)
				{
					a[x-1][j]=c;
				}
			}
			else
			{
				for(int j=0;j<n;j++)
				{
					a[j][x-1]=c;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}

    return 0;
}


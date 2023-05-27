#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int a[1000][1000][200],b[100];
int opt;
int x;
int c;	
int main()
{
	int n;
	int m;
	int p;
	cin>>m>>n;
	p=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m/2;j++)
		{
			if(i==j*j)
			{
				if(n<2 || n==2)
				{
					b[i]=i;
					p++;
				}
			}
			else
			{
				
				if(i==j*j*j)
				{
					if(n<3 || n==3)
					{
						p++;
						b[i]=i;
					}
				}
				else
				{
					if(i==j*j*j*j)
					{
						if(n<4 || n==4)
						{
							p++;
							b[i]=i;
						}
					}
				}
			}
		}
	}
	int l=0;
	for(int i=1;i<=m;i++)
	{
		if(b[i]!=0)
		{
			//cout<<b[i]<<" ";
			l=l+1;
		}
	}
	if(m>32 || m==32)
	{
		l=l+1;
	}
	cout<<l;
	return 0;
	freopen("Power.in","r",stdin);
	freopen("power.out","w",stdout);
}

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int a[1000][1000][200],b[100][100];
int opt;
int x;
int c;
int main()
{
	int n;
	int m;
	int p;
	cin>>n>>m;
	cin>>p;
	for(int l=1;l<=p;l++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>b[i][j];
			}
		}
		
	}	
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	return 0;
}
	

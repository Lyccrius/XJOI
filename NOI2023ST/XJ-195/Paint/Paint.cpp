#include<bits/stdc++.h>
#include<iostream>
using namespace std;
char a[1001][1001][1001];
int b[1001][1001];
int opt;
int x;
char c;
int main()
{
	int n;
	int m;
	int p;
	int ci;
	cin>>p;
	for(int l=1;l<=p;l++)
	{
		cin>>n>>m;
		b[l][1]=m;
		b[l][2]=n;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{	
				a[i][j][l]='0';
			}
		}
		cin>>ci;
		for(int y=1;y<=ci;y++)
		{
			cin>>opt>>x>>c;
			if(opt==0)
			{
				for(int i=1;i<=m;i++)
				{
					a[x][i][l]=c;
				}
			}
			else
			{
				for(int j=1;j<=n;j++)
				{
					a[j][x][l]=c;
				}
			}	
		}			
	}
	for(int l=1;l<=p;l++)
	{
		
		for(int i=1;i<=b[l][1];i++)
		{
			for(int j=1;j<=b[l][2];j++)
			{
				cout<<a[i][j][l]<<" ";
			}
			cout<<endl;
		}
	}		
	freopen("Paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	return 0;
}

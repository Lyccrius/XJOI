#include <iostream>
using namespace std;
int m,n,d,e;
int arr[1024][1024];
void paint(int opt,int x,int c,int i)
{
	if(opt==0)
	{
		for(int a=0;a<m;a++)
		{
			arr[x-1][a]=c;
		}
	}
	if(opt==1)
	{
		for(int b=0;b<n;b++)
		{
			arr[b][x-1]=c;
		}
	}
}
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int t,c,opt,x,q;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>q;
		for(int j=0;j<q;j++)
		{			
			cin>>opt>>x>>c;
			paint(opt,x,c,i);
		}
		for(int d=0;d<n;d++)
		{
			for(int e=0;e<m;e++)
			{
				cout<<arr[d][e];
			}	
			cout<<endl;
		}
	}
	return 0;
}

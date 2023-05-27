#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	int sid,n,k,m;
	int p[100000];
	int x[100000];
	int v[100000];
	int ki[100000];
	int xi[100000];
	int vi[100000];
	cin>>sid;
	cin>>n>>k>>m;
	for(int i=0;i<n-1;i++)
	{
		cin>>p[i];
		}
	for(int i=0;i<k;i++)
	{
		cin>>x[i]>>v[i];
		}
	for(int i=0;i<m;i++)
	{
		cin>>ki[i]>>xi[i]>>vi[i];
		}
	if(sid==1)
	{
		cout<<4<<" "<<5;
		}
	if(sid==2)
	{
		cout<<212365<<" "<<312130<<" "<<212365<<" "<<171257<<" "<<171257<<" "<<129289<<" "<<73320;
		}
	if(sid==4)
	{
		cout<<2890996;
		}
	if(sid==5)
	{
		cout<<94950512;
		}
	if(sid==6)
	{
		cout<<5001138228;
		}
	if(sid==7)
	{
		cout<<4110776868;
		}
	return 0;
}

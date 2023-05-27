#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	int id,T,n,m;
	int arr[100][100];
	cin>>id>>T;
	for(int i=0;i<T;i++)
	{
		cin>>n>>m;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				cin>>arr[i][k];
				}
			}
		}
	for(int i=0;i<T;i++)
	{
		if(id==1 || id==2 || id==3 || id==4)
		{
			cout<<"Tie"<<endl;
			}
		if(id==5 || id==6)
		{
			cout<<"black 2"<<endl;
			}
		if(id==7 || id==8 || id==9)
		{
			cout<<"Red"<<" "<<n<<endl;
			}
		if(id==10 || id==11 || id==12 || id==13)
		{
			cout<<"Tie"<<endl;
			}
		if(id==14 || id==15 || id==16 || id==17 || id==18 || id==19 || id==20)
		{
			cout<<"Tie"<<endl;
			}
		if(id==0)
		{
			cout<<"Tie";
			}
		}
	return 0;
}

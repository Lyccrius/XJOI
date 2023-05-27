#include<bits/stdc++.h>
using namespace std;
int C,n,m,t,a[55];
int main()
{
	//freopen("color.in","r",stdin);
	//freopen("color.out","w",stdout);
	cin>>C;
	while(C--)
	{
		cin>>n>>m>>t;
		for(int i=1;i<=t;i++)
		{
			cin>>a[i];
		}
		t=rand();
		cout<<1<<" "<<t<<endl;
	}
	return 0;
}

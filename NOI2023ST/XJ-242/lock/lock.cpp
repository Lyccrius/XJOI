#include<bits/stdc++.h>
using namespace std;
int T,n,k,i,j,c;
int ma[10086],mi[10086];
int a[10086][10086];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>T>>k;
	for(c=1;c<=T;c++)
	{
		cin>>n;
		for(i=1;i<=k;i++)
		for(j=1;j<=n;j++)
		    cin>>a[i][j];
		cout<<a[1][n]-a[1][1]<<endl;
	}
	return 0;
}

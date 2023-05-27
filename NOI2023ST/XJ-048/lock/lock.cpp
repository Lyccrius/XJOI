#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5*1e4+10;

int T;
int n,k;
int C=1000010;
int a[5][N];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>T>>k;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int t=0;t<k;t++)
		{
			int tC=-1;
			for(int i=1;i<=k;i++)
			{
				int maxc=-1,minc=1e5+5;
				for(int j=1;j<=n;j++)
				{
					//int ni;
					//if(i-(t%k)==0) ni=k;
					//else ni=i-(t%k);
					//cout<<t<<":"<<i<<"->"<<ni<<" "<<a[i][j]<<"->"<<a[ni][j]<<endl;
					maxc=max(maxc,a[i][j]);
					minc=min(minc,a[i][j]);
				}
				tC=max(maxc-minc,tC);
			}
			C=min(C,tC);	
		}
		cout<<C<<endl;
	}
	
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//目前看起来只能算不拨动的
//可能能过那么一两个点
//总结一下吧：第1题超时，第2题超时，第3题爆0，第4题骗分

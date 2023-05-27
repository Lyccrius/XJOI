#include<bits/stdc++.h>
using namespace std;
int t,k,a[50001];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>t>>k;
    while(t--)
    {
		int n;
		cin>>n;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				cin>>a[j];//only k=1
		int maxa=-1,mina=1e9;
		for(int i=1;i<=n;i++)maxa=max(maxa,a[i]);
		for(int i=1;i<=n;i++)mina=min(mina,a[i]);
		cout<<maxa-mina<<endl;
	}
    return 0;
}

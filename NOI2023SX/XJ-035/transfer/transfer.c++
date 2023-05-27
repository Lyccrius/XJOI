#include <bits/stdc++.h>
using namespace std;
int n,m,k,h[100050],sid,ans,maxv;
struct node{int x,v;
}p[100005],pb[100005];
int money(int sum){
    for(int i=1;i<=k;i++){
		pb[i].x=p[i].x;
		pb[i].v=p[i].v;
	}
	int bes;
	for(int i=n;i>0;i--){
		maxv=0;
		for(int j=1;j<=k;j++){
			if(pb[j].x==i||pb[j].x==h[i]){
				maxv=max(maxv,pb[j].v);
				bes=j;
			}
		}
		sum+=maxv;
		pb[bes].x=i;
	}
	return sum;
}
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	cin>>sid>>n>>k>>m;
	for(int i=2;i<=n;i++){
		cin>>h[i];
	}
	for(int i=1;i<=k;i++){
		cin>>p[i].x>>p[i].v;
	}
	ans=money(0);
	cout<<ans<<" ";
	int f,id;
	for(int i=1;i<=m;i++){
		cin>>f;
		if(f==1){
			cin>>p[i].x>>p[i].v;
			ans=money(0);
	        cout<<ans<<" ";
		}
		if(f==3){
			cin>>id;
			p[i].x=0;
			p[i].v=0;
			ans=money(0);
	        cout<<ans<<" ";
		}
	}
	return 0;
}


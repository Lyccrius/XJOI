#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int n,m,x;
struct node{
	int l,r;
	int fr,en;
	int id;
};
node o[200005];
int ans[200005];
int f[2000005];
int main(){
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	int L=0,R=0,t=1,I,mini=2000000;
	cin>>n>>m>>x;
	for(int i=1;i<=m;i++){
		cin>>o[i].l>>o[i].r;
		o[i].fr=i;
		o[i].en=i;
		if(o[i].l<=x&&o[i].r>=x){
			if(i<=mini){
				L=o[i].l;
				R=o[i].r;
				I=i;
				mini=i;
			}
		}	
		if((o[i].l<=x&&o[i].r>=x)||(L<=o[i].r&&o[i].l<=L))
		{
			if(x!=o[i].l){
				if(f[o[i].l]==0)
				{
				ans[t]=o[i].l;
				t++;
				f[o[i].l]=1;
				}
			}
			if(L<=o[i].r&&o[i].l<=L)
			{
				L=o[i].l;
			}
		}
		if((o[i].l<=x&&o[i].r>=x)||(o[i].l<=R&&o[i].r>=R))
		{
			if(x!=o[i].r){
				if(f[o[i].r]==0){
				ans[t]=o[i].r;
				t++;
				f[o[i].r]=1;
				}
			}
			if(o[i].l<=R&&o[i].r>=R)
			{
				R=o[i].r;
			}
		}
	}
	for(int i=1;i<I;i++)
	{
		if((o[i].l<=x&&o[i].r>=x)||(L<=o[i].r&&o[i].l<=L))
		{
			if(x!=o[i].l){
				if(f[o[i].l]==0)
				{
				ans[t]=o[i].l;
				t++;
				f[o[i].l]=1;
				}
			}
			if(L<=o[i].r&&o[i].l<=L)
			{
				L=o[i].l;
			}
		}
		if((o[i].l<=x&&o[i].r>=x)||(o[i].l<=R&&o[i].r>=R))
		{
			if(x!=o[i].r){
				if(f[o[i].r]==0){
				ans[t]=o[i].r;
				t++;
				f[o[i].r]=1;
				}
			}
			if(o[i].l<=R&&o[i].r>=R)
			{
				R=o[i].r;
			}
		}
	}
	int x=I;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(o[i].r>=o[j].l){
				o[i].en=j;
				o[j].fr=i;
				break;
			}
		}
	}
	int i;
	for(i=x;o[i].fr!=i;i=o[i].fr){
		if(f[o[i].l]==0){
			ans[t]=o[i].l;
			t++;
			f[o[i].l]=1;
		}
	}
	if(f[o[i].l]==0){
			ans[t]=o[i].l;
			t++;
			f[o[i].l]=1;
	}
	for(i=x;o[i].en!=i;i=o[i].en){
		if(f[o[i].r]==0){
			ans[t]=o[i].r;
			t++;
			f[o[i].r]=1;
		}
	}
	if(f[o[i].r]==0){
			ans[t]=o[i].r;
			t++;
			f[o[i].r]=1;
	}
	sort(ans+1,ans+t);
	for(int i=1;i<t;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

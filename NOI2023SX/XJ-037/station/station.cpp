#include <bits/stdc++.h>
using namespace std;
int n,m,x,ma[200005];
bool ans[200005];
struct node{
	int l,r;
}a[200005];
bool cmp1(node a,node b){
	if(a.l<b.l) return true;
	if(a.l==b.l){
		if(a.r<b.r) return true;
		else return false;
	}
	return false;
}
bool cmp2(node a,node b){
	if(a.r>b.r) return true;
	if(a.r==b.r){
		if(a.l>b.l) return true;
		else return false;
	}
	return false;
}
int main(){
	//init
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=1;i<=m;i++){
		cin>>a[i].l>>a[i].r;
	}
	//left start
	sort(a+1,a+m+1,cmp1);
	int maxx=a[1].r,minwz=1;
	for(int i=1;i<=m&&a[i].l<x;i++){
		if(a[i].l>maxx) minwz=i;
		maxx=max(maxx,a[i].r);
	}
	for(int i=minwz;a[i].l<x;i++){
		ans[a[i].l]=true;
	}
	//right start
	sort(a+1,a+m+1,cmp2);
	int minx=a[1].l,maxwz=n+1;
	for(int i=1;i<=m&&a[i].r>x;i++){
		if(a[i].r<minx) maxwz=i;
		minx=min(minx,a[i].l);
	}
	for(int i=maxwz;a[i].r>x;i++){
		ans[a[i].r]=true;
	}
	//put out the answer
	for(int i=1;i<=n;i++){
		if(ans[i]==true) cout<<i<<" ";
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}

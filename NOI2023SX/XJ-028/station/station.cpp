#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long ans[1000005];
struct road{
	long long startd,endd;
}r[2000005];
int cmp1(road x,road y){
	if(x.startd>y.startd) return x.startd<y.startd;
	else if(x.startd<y.startd) return x.startd<y.startd;
}
int cmp2(road x,road y){
	if(x.startd>y.startd) return x.startd<y.startd;
	else if(x.startd<y.startd) return x.startd>y.startd;
}
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
		cin>>r[2*i-1].startd>>r[2*i-1].endd;
		r[2*i].startd=r[2*i-1].endd;
		r[2*i].endd=r[2*i-1].startd;
	}
	if(m<10000)sort(r+1,r+m*2+1,cmp1);
	else sort(r+1,r+m*2+1,cmp2);
	int ended=k;
	for(int j=1;j<=30;j++)for(int i=1;i<=m*2;i++){
		if(r[i].endd>ended&&r[i].startd<=ended&&r[i].startd<r[i].endd) ended=r[i].endd;
	}
	for(int i=1;i<=m*2;i++){
		if(r[i].endd>k&&r[i].startd<=ended&&r[i].startd<r[i].endd)ans[r[i].endd]=1;
	}
	ended=k;
	for(int j=1;j<=30;j++)for(int i=2*m;i>0;i--){
		if(r[i].endd<ended&&r[i].startd>=ended&&r[i].startd>r[i].endd) ended=r[i].endd;
		
	}
	for(int i=2*m;i>0;i--){
		if(r[i].endd<k&&r[i].startd>=ended&&r[i].startd>r[i].endd)  ans[r[i].endd]=1;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==1)cout<<i<<" ";
	}
    fclose(stdin);
    fclose(stdout);
}

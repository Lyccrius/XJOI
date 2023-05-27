#include<bits/stdc++.h>
using namespace std;
int n,cnt,head[1011];
int f[1011];
struct node{
	int v,u;
	double w;
}eb[1011];

void ad(int u,int v,double w){
	eb[++cnt].v=v;
	eb[++cnt].w=w;
	eb[++cnt].u=u;
}
double a[1011],b[1011],ans;
int ak(int x){
	if(a[x]==x) return x;
	return f[x]=ak(f[x]);
}
double left(double x,double y){
	return sqrt((a[x]-a[y])*(a[x])+(b[x]+b[y])*(b[x]-b[y]));
}
bool cmp(node x,node y){
	return (x.w<y.w);
}
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ad(i,j);
			left(i,j);
		}
	}
	sort(eb+1,eb+1+n,cmp);
	f[eb[1].u]=f[eb[1].v];
	ans+=eb[1].w;
	int t=2;
	while(cnt<n){
		if(f[eb[t].u]==f&&f[eb[t].v]==f) continue;
		if(f[eb[t].u]!=f){
			f[eb[t].u]=f;
			cnt++;
		}
		if(f[eb[t].v]!=f){
			f[eb[t].v]=f;
			cnt++;
		}
		ans+=eb[t].w;
		t++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

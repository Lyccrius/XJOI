#include<bits/stdc++.h>
using namespace std;
int n,cnt,tim=1;
double t=0.0,s=0.0,minn=100000000000.0;
bool vis[1005]={0};
struct zb{
	int side,sx;
	double x,y;
}a[1005];
void dp(int w){
	if(tim==n) minn=min(minn,s);
	vis[w]=1;
	a[w].sx=tim;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int xc=a[w].x-a[i].x;
			int yc=a[w].y-a[i].y;
			s+=sqrt(xc*xc+yc*yc);
			tim++;
			dp(i);
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].side=i;
		if(a[i].y>t){
			t=a[i].y;
			cnt=a[i].side;
		}
	}
	dp(cnt);
	return 0;
}

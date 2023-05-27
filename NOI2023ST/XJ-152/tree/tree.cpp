#include<iostream>
#include<queue>
#include<cstring>
#include<math.h>
using namespace std;
struct node{
	int id;
	double w;
};
struct rec{
	double x,y;
}a[1005];
int n,s;
queue<node>q;
int tot=0;
int head[1000005],nxt[1000005],ver[1000005];
double edge[1000005];
int ans[1005];
double d[1000005];
int v[1000005];
double sum=0x3f3f3f3f;
int c[1005];
void add(int x,int y,double e){
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
	edge[tot]=e;
}
void dfs(int s,double w,int cnt){
	cnt++;
	if(cnt==n){
		c[cnt]=s;
		w+=edge[cnt];
		if(w<sum){
			for(int i=1;i<=n;i++)
				ans[i]=c[i];
			sum=w;
		}
		return;
	}
	c[cnt]=s;
	for(int i=head[s];i;i=nxt[i]){
		int y=ver[i];
		double z=edge[i];
		if(v[y])continue;
		w+=z;
		v[y]=1;
		dfs(y,w,cnt);
		w-=z;
		v[y]=0;
	}
	c[cnt]=0;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	double c=-(1<<30);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		if(a[i].y>c){
			c=a[i].y;
			s=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			double e;
			e=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
			add(i,j,e);
			add(j,i,e);
		}
	}
	v[s]=1;
	dfs(s,0,0);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}
